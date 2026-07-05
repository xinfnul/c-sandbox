#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *front;
  Node *rear;
} Queue;

void initQueue(Queue *q);

bool isEmpty(Queue *q);

void enqueue(Queue *q, int value);

int dequeue(Queue *q);

int peek(Queue *q);

void displayQueue(Queue *q);

void freeQueue(Queue *q);

#endif
