#ifndef QUEUE_H
#define QUEUE_H

#define WHITE 0
#define GRAY 1
#define BLACK 2

struct queue {
	int head, tail;
	int *q;
	int *color;
}

void queue_create(struct queue *self, size_t size);

void enqueue(struct queue *self, int x);

int dequeue(struct queue *self);

#endif //QUEUE_H
