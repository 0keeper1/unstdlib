#include "_unstdcommon.h"
#include <stdatomic.h>

/* A forward declaration used for unstdqueue_t */
typedef struct unstdqueue_node unstdqueue_node;

/* Structure representing the queue itself */
typedef struct unstdqueue_t {
    atomic_ulong current_size;        // Current number of items in the queue
    atomic_ulong allocated_size;      // Number of nodes allocated (used for pre-allocation)
    u64t max_capacity;                // Maximum number of items the queue can hold
    unstdqueue_node *head;            // Pointer to the first node in the queue
    unstdqueue_node *tail;            // Pointer to the last node in the queue
    unstdqueue_node *free_list;       // Pointer to the list of free (unused) nodes
} unstdqueue_t;

/**
 * @brief Initializes a queue with optional pre-allocation and maximum capacity.
 * @details If a `preallocate_size_arg` greater than `max_capacity_arg` is passed,
 *          and `max_capacity_arg` is greater than zero,
 *          `max_capacity_arg` will be used as the value for `preallocate_size_arg`.
 * @param preallocate_size_arg The number of nodes to preallocate. Pass 0 to skip pre-allocation.
 * @param max_capacity_arg The maximum number of items the queue can hold. Pass 0 for unlimited capacity.
 * @param out_error_arg Pointer to store the error code (optional). Pass NULL to ignore.
 * @returns A pointer to the initialized queue, or NULL on failure.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Failure. <code>memset()</code> failed.
 * @retval NULL Failure due to memory allocation error or invalid parameter.
 */
extern unstdqueue_t *unstdqueue_init(
        u64t preallocate_size_arg,
        const u64t max_capacity_arg,
        u8t *const out_error_arg
);

/**
 * @brief Enqueues an item into the queue.
 * @param queue_arg Pointer to the queue structure.
 * @param buffer_arg Pointer to the data to enqueue.
 * @returns A number indicating the state of the operation.
 * @retval [1] Success.
 * @retval [2] Insufficient parameter. `queue_arg` is NULL. See `queue_arg`.
 * @retval [3] Insufficient parameter. `buffer_arg` is NULL. See `buffer_arg`.
 * @retval [4] Failure. <code>memset()</code> failed.
 * @retval [5] Error. Queue is full (max_capacity reached).
 */
extern u8t unstdqueue_enqueue(
        unstdqueue_t *const queue_arg,
        void *const buffer_arg
);

/**
 * @brief Dequeues an item from the queue.
 * @param queue_arg Pointer to the queue structure.
 * @param out_error_arg Pointer to store the error code (optional). Pass NULL to ignore.
 * @returns A pointer to the dequeued data, or NULL on failure.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Insufficient parameter. `queue_arg` is NULL. See `queue_arg`.
 * @OutParamValue [3] Error. Queue is empty (max_capacity reached).
 * @OutParamValue [4] Error. Queue is empty (should not occur under normal circumstances
 *                           and is therefore considered an unexpected state).
 */
void *unstdqueue_dequeue(
        unstdqueue_t *queue_arg,
        u8t *const out_error_arg
);

/**
 * @brief Gets the current size of the queue.
 * @param queue_arg Pointer to the queue structure.
 * @param out_error_arg Pointer to store the error code (optional). Pass NULL to ignore.
 * @returns The current size of the queue, or 0 on failure (always check for error).
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Insufficient parameter. `queue_arg` is NULL. See `queue_arg`.
 */
u64t unstdqueue_size(
        unstdqueue_t *queue_arg,
        u8t *const out_error_arg
);

/**
 * @brief Checks if the queue is empty.
 * @param queue_arg Pointer to the queue structure.
 * @returns A number (u8t) indicating the state of the operation.
 * @retval [0] False
 * @retval [1] True.
 * @retval [2] Insufficient parameter. `queue_arg` is NULL. See `queue_arg`.
 */
u8t unstdqueue_isempty(
        unstdqueue_t *queue_arg
);


/**
 * @brief Checks if the queue is full.
 * @param queue_arg Pointer to the queue structure.
 * @returns A number (u8t) indicating the state of the operation.
 * @retval [0] False
 * @retval [1] True.
 * @retval [2] Insufficient parameter. `queue_arg` is NULL. See `queue_arg`.
 */
u8t unstdqueue_isfull(
        const unstdqueue_t *const queue_arg
);

/**
 * @brief Peeks at the front item of the queue without dequeuing.
 * @param queue_arg Pointer to the queue structure.
 * @param out_error_arg Pointer to store the error code (optional). Pass NULL to ignore.
 * @returns A pointer to the front item, or NULL on failure.
 * @OutParamValue [1] Success.
 * @OutParamValue [2] Invalid queue_arg parameter (NULL).
 * @OutParamValue [3] Queue is empty.
 */
void *unstdqueue_peek(
        unstdqueue_t *queue_arg,
        u8t *const out_error_arg
);

/**
 * @brief Frees the queue and all associated memory.
 * @param queue_arg Pointer to the queue structure.
 * @returns A number indicating the state of the operation.
 * @retval [1] Success.
 * @retval [2] Invalid queue_arg parameter (NULL).
 */
u8t unstdqueue_free(
        unstdqueue_t *const queue_arg
);