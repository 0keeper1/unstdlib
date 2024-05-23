/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Evan Teran
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef UNSTDLIB_UNSTDVECTOR_H
#define UNSTDLIB_UNSTDVECTOR_H

#include <stdlib.h> /* for realloc */
#include <assert.h> /* for assert */
#include <string.h> /* for memmove */

typedef void (*unstdvector_elem_destructor_t)(void *elem);

typedef struct unstdvector_metadata_t {
    sizet size;
    sizet capacity;
    unstdvector_elem_destructor_t elem_destructor;
} unstdvector_metadata_t;

/**
 * @brief The vector type used in this library.
 */
#define unstdvector_vector_typeM(type_arg) type_arg *

/**
 * @brief Syntactic sugar to retrieve a vector type.
 * @param type_arg The type of vector to act on.
 */
#define unstdvectorM(type_arg) unstdvector_vector_typeM(type_arg)

/**
 * @brief The iterator type used for unstdvectorM.
 */
#define unstdvector_iteratorM(type_arg) unstdvector_vector_typeM(type_arg)

/**
 * @brief Converts a vector pointer to a metadata pointer.
 * @param vector_arg A vector.
 * @returns The metadata pointer of the vector.
 */
#define _unstdvector_vec_to_baseM(vector_arg) \
    (&((unstdvector_metadata_t *)(vector_arg))[-1])

/**
 * @brief For internal use, converts a metadata pointer to a vector pointer.
 * @param ptr_arg A pointer to the metadata.
 * @returns A vector.
 */
#define _unstdvector_base_to_vecM(ptr_arg) \
    ((void *)&((unstdvector_metadata_t *)(ptr_arg))[1])

/**
 * @brief Gets the current capacity of the vector.
 * @param vector_arg A vector.
 * @returns The capacity as a sizet.
 */
#define unstdvector_capacityM(vector_arg) \
    ((vector_arg) ? _unstdvector_vec_to_baseM(vector_arg)->capacity : (sizet)0)

/**
 * @brief Gets the current size of the vector.
 * @param vec_arg A vector.
 * @returns The size as a sizet.
 */
#define unstdvector_sizeM(vec) \
    ((vec) ? _unstdvector_vec_to_baseM(vec)->size : (sizet)0)

/**
 * @brief Get the element destructor function used<br>
 *        to clean up elements.
 * @param vector_arg A vector.
 * @returns A function pointer as unstdvector_elem_destructor_t.
 */
#define unstdvector_elem_destructorM(vector_arg) \
    ((vector_arg) ? _unstdvector_vec_to_baseM(vector_arg)->elem_destructor : NULL)

/**
 * @brief Checks whether a vector is empty.
 * @param vector_arg A vector
 * @returns non-zero if empty, zero if non-empty
 */
#define unstdvector_emptyM(vector_arg) \
    (unstdvector_sizeM(vector_arg) == 0)

/**
 * @brief Requests that the vector capacity be at least enough<br>
 *        to contain n elements. 
 * @details If n is greater than the current vector capacity, the<br>
 *          function causes the container to reallocate its storage increasing its<br>
 *          capacity to n (or greater).
 * @param vector_arg A vector.
 * @param n_arg Minimum capacity for the vector.
 * @returns void.
 */
#define unstdvector_reserveM(vector_arg, n_arg)                  \
    do {                                                         \
        sizet unstdv_cap__ = unstdvector_capacityM(vector_arg); \
        if (unstdv_cap__ < (n_arg)) {                            \
            _unstdvector_growM((vector_arg), (n_arg));           \
        }                                                        \
    } while (0)

/**
 * @brief Initializes a vector.
 * @details The vector must be NULL for this to do anything.
 * @param vector_arg A vector.
 * @param capacity_arg Vector capacity to reserve.
 * @param elem_destructor_fn_arg Element destructor function.
 * @returns void.
 */
#define unstdvector_initM(vector_arg, capacity_arg, elem_destructor_fn_arg)          \
    do {                                                                             \
        if (!(vector_arg)) {                                                         \
            unstdvector_reserveM((vector_arg), capacity);                            \
            unstdvector_set_elem_destructor((vector_arg), (elem_destructor_fn_arg)); \
        }                                                                            \
    } while (0)

/**
 * @brief Removes the element at index i from the vector.
 * @param vector_arg A vector.
 * @param index_arg Index of element to remove.
 * @returns void.
 */
#define unstdvector_eraseM(vector_arg, index_arg)                                                           \
    do {                                                                                                    \
        if (vector_arg) {                                                                                   \
            const sizet unstdv_sz__ = unstdvector_sizeM(vector_arg);                                       \
            if ((index_arg) < unstdv_sz__) {                                                                \
                unstdvector_elem_destructor_t elem_destructor__ = unstdvector_elem_destructorM(vector_arg); \
                if (elem_destructor__) {                                                                    \
                    elem_destructor__(&(vector_arg)[index_arg]);                                            \
                }                                                                                           \
                _unstdvector_set_sizeM((vector_arg), unstdv_sz__ - 1);                                      \
                memmove(                                                                                    \
                    (vector_arg) + (index_arg),                                                             \
                    (vector_arg) + (index_arg) + 1,                                                         \
                    sizeof(*(vector_arg)) * (unstdv_sz__ - 1 - (index_arg)));                               \
            }                                                                                               \
        }                                                                                                   \
    } while (0)

/**
 * @brief Erase all of the elements in the vector.
 * @param vector_arg A vector.
 * @returns void.
 */
#define unstdvector_clearM(vector_arg)                                                                  \
    do {                                                                                                \
        if (vector_arg) {                                                                               \
            unstdvector_elem_destructor_t elem_destructor__ = unstdvector_elem_destructorM(vector_arg); \
            if (elem_destructor__) {                                                                    \
                sizet i__;                                                                             \
                for (i__ = 0; i__ < unstdvector_sizeM(vector_arg); ++i__) {                             \
                    elem_destructor__(&(vector_arg)[i__]);                                              \
                }                                                                                       \
            }                                                                                           \
            _unstdvector_set_sizeM(vector_arg, 0);                                                      \
        }                                                                                               \
    } while (0)

/**
 * @brief Frees all memory associated with the vector.
 * @param vector_arg A vector.
 * @returns void.
 */
#define unstdvector_freeM(vector_arg)                                                                   \
    do {                                                                                                \
        if (vector_arg) {                                                                               \
            void *p1__ = _unstdvector_vec_to_baseM(vector_arg);                                         \
            unstdvector_elem_destructor_t elem_destructor__ = unstdvector_elem_destructorM(vector_arg); \
            if (elem_destructor__) {                                                                    \
                sizet i__;                                                                             \
                for (i__ = 0; i__ < unstdvector_sizeM(vector_arg); ++i__) {                             \
                    elem_destructor__(&(vector_arg)[i__]);                                              \
                }                                                                                       \
            }                                                                                           \
            free(p1__);                                                                                 \
        }                                                                                               \
    } while (0)

/**
 * @brief Returns an iterator to first element of the vector.
 * @param vector_arg A vector.
 * @returns A pointer to the first element (or NULL).
 */
#define unstdvector_beginM(vector_arg) \
    (vector_arg)

/**
 * @brief Returns an iterator to one past the last element of the vector.
 * @param vec A vector.
 * @returns a pointer to one past the last element (or NULL).
 */
#define unstdvector_endM(vector_arg) \
    ((vector_arg) ? &((vector_arg)[unstdvector_sizeM(vector_arg)]) : NULL)

/**
 * @brief Returns an the computed size in next vector grow.
 * @details Size is increased by multiplication of 2.
 * @param size_arg Current size.
 * @returns Size after next vector grow.
 */
#define unstdvector_compute_next_grow_logarithmicM(size_arg) \
    ((size_arg) ? ((size_arg) << 1) : 1)

/**
 * @brief Returns an the computed size in next vector grow.
 * @details Size is increased by 1.
 * @param size_arg Current size.
 * @returns Size after next vector grow.
 */
#define unstdvector_compute_next_growM(size_arg) \
    ((size_arg) + 1)

/**
 * @brief Adds an element to the end of the vector.
 * @param vector_arg A vector.
 * @param value_arg The value to add.
 * @returns void.
 */
#define unstdvector_pushbackM(vector_arg, value_arg)                                        \
    do {                                                                                    \
        sizet unstdv_cap__ = unstdvector_capacityM(vector_arg);                            \
        if (unstdv_cap__ <= unstdvector_sizeM(vector_arg)) {                                \
            _unstdvector_growM((vector_arg), unstdvector_compute_next_growM(unstdv_cap__)); \
        }                                                                                   \
        (vector_arg)[unstdvector_sizeM(vector_arg)] = (value_arg);                          \
        _unstdvector_set_sizeM((vector_arg), unstdvector_sizeM(vector_arg) + 1);            \
    } while (0)

/**
 * @brief Adds an element to the end of the vector.
 * @param vector_arg A vector.
 * @param value_arg The value to add.
 * @returns void.
 */
#define unstdvector_pushback_logarithmicM(vector_arg, value_arg)                                        \
    do {                                                                                                \
        sizet unstdv_cap__ = unstdvector_capacityM(vector_arg);                                        \
        if (unstdv_cap__ <= unstdvector_sizeM(vector_arg)) {                                            \
            _unstdvector_growM((vector_arg), unstdvector_compute_next_grow_logarithmicM(unstdv_cap__)); \
        }                                                                                               \
        (vector_arg)[unstdvector_sizeM(vector_arg)] = (value_arg);                                      \
        _unstdvector_set_sizeM((vector_arg), unstdvector_sizeM(vector_arg) + 1);                        \
    } while (0)

/**
 * @brief insert element at position pos to the vector.
 * @param vector_arg A vector.
 * @param position_arg Position in the vector where the new elements are inserted.
 * @param value_arg Value to be copied (or moved) to the inserted elements.
 * @returns void.
 */
#define unstdvector_insertM(vector_arg, position_arg, value_arg)                             \
    do {                                                                                     \
        sizet unstdv_cap__ = unstdvector_capacityM(vector_arg);                             \
        if (unstdv_cap__ <= unstdvector_sizeM(vector_arg)) {                                 \
            _unstdvector_growM((vector_arg), unstdvector_compute_next_growM(unstdv_cap__));  \
        }                                                                                    \
        if ((position_arg) < unstdvector_sizeM(vector_arg)) {                                \
            memmove(                                                                         \
                (vector_arg) + (position_arg) + 1,                                           \
                (vector_arg) + (position_arg),                                               \
                sizeof(*(vector_arg)) * ((unstdvector_sizeM(vector_arg)) - (position_arg))); \
        }                                                                                    \
        (vector_arg)[(position_arg)] = (value_arg);                                          \
        _unstdvector_set_sizeM((vector_arg), unstdvector_sizeM(vector_arg) + 1);             \
    } while (0)

/**
 * @brief Insert element at position pos to the vector.
 * @param vector_arg A vector.
 * @param position_arg Position in the vector where the new elements are inserted.
 * @param value_arg - value to be copied (or moved) to the inserted elements.
 * @returns void.
 */
#define unstdvector_insert_logarithmicM(vector_arg, position_arg, value_arg)                            \
    do {                                                                                                \
        sizet unstdv_cap__ = unstdvector_capacityM(vector_arg);                                        \
        if (unstdv_cap__ <= unstdvector_sizeM(vector_arg)) {                                            \
            _unstdvector_growM((vector_arg), unstdvector_compute_next_grow_logarithmicM(unstdv_cap__)); \
        }                                                                                               \
        if ((position_arg) < unstdvector_sizeM(vector_arg)) {                                           \
            memmove(                                                                                    \
                (vector_arg) + (position_arg) + 1,                                                      \
                (vector_arg) + (position_arg),                                                          \
                sizeof(*(vector_arg)) * ((unstdvector_sizeM(vector_arg)) - (position_arg)));            \
        }                                                                                               \
        (vector_arg)[(position_arg)] = (value_arg);                                                     \
        _unstdvector_set_sizeM((vector_arg), unstdvector_sizeM(vector_arg) + 1);                        \
    } while (0)

/**
 * @brief Removes the last element from the vector.
 * @param vector_arg The vector.
 * @returns void.
 */
#define unstdvector_pop_backM(vector_arg)                                                           \
    do {                                                                                            \
        unstdvector_elem_destructor_t elem_destructor__ = unstdvector_elem_destructorM(vector_arg); \
        if (elem_destructor__) {                                                                    \
            elem_destructor__(&(vector_arg)[unstdvector_sizeM(vector_arg) - 1]);                    \
        }                                                                                           \
        _unstdvector_set_sizeM((vector_arg), unstdvector_sizeM(vector_arg) - 1);                    \
    } while (0)

/**
 * @brief Copies a vector.
 * @param from_arg The original vector.
 * @param to_arg Destination to which the function copies to.
 * @returns void.
 */
#define unstdvector_copyM(from_arg, to_arg)                                                  \
    do {                                                                                     \
        if ((from_arg)) {                                                                    \
            _unstdvector_growM(to_arg, unstdvector_sizeM(from_arg));                         \
            _unstdvector_set_sizeM(to_arg, unstdvector_sizeM(from_arg));                     \
            memcpy((to_arg), (from_arg), unstdvector_sizeM(from_arg) * sizeof(*(from_arg))); \
        }                                                                                    \
    } while (0)

/**
 * @brief Exchanges the content of the vector by the content of another vector of the same type.
 * @param vector_arg The original vector.
 * @param other_arg The other vector to swap content with.
 * @param type_arg The type of both vectors.
 * @returns void.
 */
#define unstdvector_swapM(vector_arg, other_arg, type_arg)                 \
    do {                                                                   \
        if (vector_arg && other_arg) {                                     \
            unstdvector_vector_typeM(type_arg) unstdv_swap__ = vector_arg; \
            vector_arg = other_arg;                                        \
            other_arg = unstdv_swap__;                                     \
        }                                                                  \
    } while (0)

/**
 * @brief Sets the capacity variable of the vector.
 * @param vector_arg The vector.
 * @param size_arg The new capacity to set.
 * @returns void.
 */
#define _unstdvector_set_capacityM(vector_arg, size_arg)                  \
    do {                                                                  \
        if (vector_arg) {                                                 \
            _unstdvector_vec_to_baseM(vector_arg)->capacity = (size_arg); \
        }                                                                 \
    } while (0)

/**
 * @brief Sets the size variable of the vector.
 * @param vector_arg The vector.
 * @param size_arg The new capacity to set.
 * @returns void.
 */
#define _unstdvector_set_sizeM(vector_arg, size_arg)                  \
    do {                                                              \
        if (vector_arg) {                                             \
            _unstdvector_vec_to_baseM(vector_arg)->size = (size_arg); \
        }                                                             \
    } while (0)

/**
 * @brief Sets the element destructor function.
 * @details Used to clean up removed elements.
 * @param vector_arg The vector.
 * @param elem_destructor_fn_arg Function pointer of type unstdvector_elem_destructor_t used to destroy elements.
 * @returns void.
 */
#define unstdvector_set_elem_destructorM(vector_arg, elem_destructor_fn_arg)                   \
    do {                                                                                       \
        if (vector_arg) {                                                                      \
            _unstdvector_vec_to_baseM(vector_arg)->elem_destructor = (elem_destructor_fn_arg); \
        }                                                                                      \
    } while (0)

/**
 * @brief Ensures that the vector is at least `count` elements big.
 * @param vector_arg The vector.
 * @param count_arg The new capacity to set.
 * @returns void.
 */
#define _unstdvector_growM(vector_arg, count_arg)                                                        \
    do {                                                                                                 \
        const sizet unstdv_sz__ = (count_arg) * sizeof(*(vector_arg)) + sizeof(unstdvector_metadata_t); \
        if (vector_arg) {                                                                                \
            void *unstdv_p1__ = _unstdvector_vec_to_baseM(vector_arg);                                   \
            void *unstdv_p2__ = realloc(unstdv_p1__, unstdv_sz__);                                       \
            assert(unstdv_p2__);                                                                         \
            (vector_arg) = _unstdvector_base_to_vecM(unstdv_p2__);                                       \
        } else {                                                                                         \
            void *unstdv_p__ = malloc(unstdv_sz__);                                                      \
            assert(unstdv_p__);                                                                          \
            (vector_arg) = _unstdvector_base_to_vecM(unstdv_p__);                                        \
            _unstdvector_set_sizeM((vector_arg), 0);                                                     \
            unstdvector_set_elem_destructorM((vector_arg), NULL);                                        \
        }                                                                                                \
        _unstdvector_set_capacityM((vector_arg), (count_arg));                                           \
    } while (0)

/**
 * @brief Requests the container to reduce its capacity to fit its size.
 * @param vector_arg The vector.
 * @returns void.
 */
#define unstdvector_shrink_to_fitM(vector_arg)                         \
    do {                                                               \
        if (vector_arg) {                                              \
            const sizet unstdv_sz___ = unstdvector_sizeM(vector_arg); \
            _unstdvector_growM(vector_arg, unstdv_sz___);              \
        }                                                              \
    } while (0)


/**
 * @brief For header to iterate over vector each element's address.
 * @param iterator_arg - iterator of type pointer to vector element.
 * @param vector_arg The vector.
 * @returns void.
 */
#define unstdvector_for_each_inM(iterator_arg, vector_arg) \
    for (iterator_arg = unstdvector_beginM(vector_arg); iterator_arg < unstdvector_endM(vector_arg); iterator_arg++)

/**
 * @brief Calls function func on each element of the vector.
 * @param vector_arg The vector.
 * @param func_arg Function to be called on each element that takes each element as argument.
 * @returns void.
 */
#define unstdvector_for_eachM(vector_arg, func_arg)               \
    do {                                                          \
        if ((vector_arg) && (func_arg) != NULL) {                 \
            sizet i;                                             \
            for (i = 0; i < unstdvector_sizeM(vector_arg); i++) { \
                func_arg((vector_arg)[i]);                        \
            }                                                     \
        }                                                         \
    } while (0)

/**
 * @brief Calls `free_func` on each element.
 * @details Contained in the vector and then destroys the vector itself.
 * @param vector_arg The vector.
 * @param free_func Function used to free each element in the vector with.
 *                  one parameter which is the element to be freed.
 * @returns void.
 */
#define unstdvector_free_each_and_freeM(vector_arg, free_func_arg) \
    do {                                                           \
        unstdvector_for_eachM((vector_arg), (free_func_arg));      \
        unstdvector_freeM(vector_arg);                             \
    } while (0)

#endif /* UNSTDLIB_UNSTDVECTOR_H */