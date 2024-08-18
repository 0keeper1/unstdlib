#include <stdlib.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdbool.h>
#include "unstdqueue.h"

typedef struct unstdqueue_node {
    void *data;                       // Pointer to the data held by the node
    struct unstdqueue_node *next;     // Pointer to the next node in the queue
} unstdqueue_node;

unstdqueue_t *unstdqueue_init(u64t preallocate_size_arg, const u64t max_capacity_arg, u8t *const out_error_arg) {
    unstdqueue_t *queue = (unstdqueue_t *) malloc(sizeof(unstdqueue_t));
    if (!queue) {
        if (out_error_arg) {
            *out_error_arg = 2;
        }
        return NULL;
    }

    atomic_init(&queue->current_size, 0);
    atomic_init(&queue->allocated_size, 0);
    queue->max_capacity = max_capacity_arg;
    queue->head = NULL;
    queue->tail = NULL;
    queue->free_list = NULL;

    if (max_capacity_arg > 0 && preallocate_size_arg > max_capacity_arg) {
        preallocate_size_arg = max_capacity_arg;
    }

    for (u64t i = 0; i < preallocate_size_arg; ++i) {
        unstdqueue_node *node = (unstdqueue_node *) malloc(sizeof(unstdqueue_node));
        if (!node) {
            if (out_error_arg) {
                *out_error_arg = 2;
            }
            unstdqueue_free(queue);
            return NULL;
        }
        node->data = NULL;
        node->next = queue->free_list;
        queue->free_list = node;
        atomic_fetch_add(&queue->allocated_size, 1);
    }

    if (out_error_arg) {
        *out_error_arg = 1;
    }

    return queue;
}


u8t unstdqueue_enqueue(unstdqueue_t *const queue_arg, void *const buffer_arg) {
    if (!queue_arg) {
        return 2;
    }

    if (!buffer_arg) {
        return 3;
    }

    if (queue_arg->max_capacity > 0 && atomic_load(&queue_arg->current_size) >= queue_arg->max_capacity) {
        return 5;
    }

    unstdqueue_node *node;
    if (queue_arg->free_list) {
        node = queue_arg->free_list;
        queue_arg->free_list = queue_arg->free_list->next;
    } else {
        node = (unstdqueue_node *) malloc(sizeof(unstdqueue_node));
        if (!node) {
            return 4;
        }
        atomic_fetch_add(&queue_arg->allocated_size, 1);
    }

    node->data = buffer_arg;
    node->next = NULL;

    unstdqueue_node *prev_tail = queue_arg->tail;
    if (prev_tail) {
        prev_tail->next = node;
    } else {
        queue_arg->head = node;
    }
    queue_arg->tail = node;

    atomic_fetch_add(&queue_arg->current_size, 1);

    return 1;
}


void *unstdqueue_dequeue(unstdqueue_t *queue_arg, u8t *const out_error_arg) {
    if (!queue_arg) {
        if (out_error_arg) *out_error_arg = 2;
        return NULL;
    }

    if (atomic_load(&queue_arg->current_size) == 0) {
        if (out_error_arg) *out_error_arg = 3;
        return NULL;
    }

    unstdqueue_node *node = queue_arg->head;
    if (!node) {
        if (out_error_arg) *out_error_arg = 4; // Error: Queue is empty (should not occur)
        return NULL;
    }

    void *data = node->data;
    queue_arg->head = node->next;
    if (!queue_arg->head) {
        queue_arg->tail = NULL;
    }

    node->data = NULL;
    node->next = queue_arg->free_list;
    queue_arg->free_list = node;

    atomic_fetch_sub(&queue_arg->current_size, 1);

    if (out_error_arg) *out_error_arg = 1;
    return data;
}

u64t unstdqueue_size(unstdqueue_t *queue_arg, u8t *const out_error_arg) {
    if (!queue_arg) {
        if (out_error_arg) {
            *out_error_arg = 2;
        }
        return 0;
    }

    if (out_error_arg) {
        *out_error_arg = 1;
    }

    return atomic_load(&queue_arg->current_size);
}


u8t unstdqueue_isempty(unstdqueue_t *queue_arg) {
    if (!queue_arg) {
        return 2;
    }

    return atomic_load(&queue_arg->current_size) == 0;
}


u8t unstdqueue_isfull(const unstdqueue_t *const queue_arg) {
    if (!queue_arg) {
        return 2;
    }

    return queue_arg->max_capacity > 0
           && atomic_load(&queue_arg->current_size) >= queue_arg->max_capacity;
}


void *unstdqueue_peek(unstdqueue_t *queue_arg, u8t *const out_error_arg) {
    if (!queue_arg) {
        if (out_error_arg) {
            *out_error_arg = 2;
        }
        return NULL;
    }

    if (atomic_load(&queue_arg->current_size) == 0) {
        if (out_error_arg) {
            *out_error_arg = 3;
        }
        return NULL;
    }

    if (out_error_arg) *out_error_arg = 1;
    return queue_arg->head->data;
}


u8t unstdqueue_free(unstdqueue_t *const queue_arg) {
    if (!queue_arg) {
        return 2;
    }

    unstdqueue_node *current = queue_arg->head;
    while (current) {
        unstdqueue_node *next = current->next;
        free(current);
        current = next;
    }

    current = queue_arg->free_list;
    while (current) {
        unstdqueue_node *next = current->next;
        free(current);
        current = next;
    }

    free(queue_arg);
    return 1;
}
