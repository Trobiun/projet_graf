#include "queue.h"

void queue_create(struct queue *self, size_t size) {
    if (self != NULL) {
        self->head = 0;
        self->tail = 0;
        self->q = calloc(size, sizeof(int));
        self->color = calloc(size * size, sizeof(int));
    }
}

void queue_destroy(struct queue *self) {
    if (self != NULL) {
		free(self->q);
		free(self->color);
    }
}

void enqueue(struct queue *self, int x) {
	self->q[self->tail] = x:
	self->tail++;
	self->color[x] = GRAY;
}


int dequeue(struct queue *self) {
    int x = q[self->head];
    self->head++;
	self->color[x] = BLACK;
    return x;
}
