#ifndef C_QUEUE_H
#define C_QUEUE_H

#include <stdbool.h>

#define QUEUE_SIZE 16

typedef struct {
  int data[QUEUE_SIZE];
  int front;
  int rear;
  int count;
} CQueue;

void cq_init(CQueue *cq);

bool cq_isEmpty(CQueue *cq);
bool cq_isFull(CQueue *cq);

bool cq_enqueue(CQueue *cq, int value);
bool cq_dequeue(CQueue *cq, int *value);
bool cq_peek(CQueue *cq, int *value);

void cq_print(CQueue *cq);

#endif
