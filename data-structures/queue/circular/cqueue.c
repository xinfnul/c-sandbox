#include "cqueue.h"

#include <stdio.h>

void cq_init(CQueue *cq) {
  cq->front = 0;
  cq->rear = 0;
  cq->count = 0;
}

bool cq_isEmpty(CQueue *cq) { return cq->count == 0; }

bool cq_isFull(CQueue *cq) { return cq->count == QUEUE_SIZE; }

bool cq_enqueue(CQueue *cq, int value) {
  if (cq_isFull(cq)) {
    return false;
  }

  cq->data[cq->rear] = value;
  cq->rear = (cq->rear + 1) % QUEUE_SIZE;
  cq->count++;

  return true;
}

bool cq_dequeue(CQueue *cq, int *value) {
  if (cq_isEmpty(cq)) {
    return false;
  }

  *value = cq->data[cq->front];
  cq->front = (cq->front + 1) % QUEUE_SIZE;
  cq->count--;

  return true;
}

bool cq_peek(CQueue *cq, int *value) {
  if (cq_isEmpty(cq)) {
    return false;
  }

  *value = cq->data[cq->front];
  return true;
}

void cq_print(CQueue *cq) {
  if (cq_isEmpty(cq)) {
    printf("Queue is empty.\n");
    return;
  }

  printf("Queue: \n");
  for (int i = 0; i < cq->count; i++) {
    int index = (cq->front + i) % QUEUE_SIZE;
    printf("%d ", cq->data[index]);
  }
  printf("\n");
}

int main(void) {
  CQueue cq;

  cq_init(&cq);

  for (int i = 0; i < 16; i++) {
    if (!cq_enqueue(&cq, i)) {
      printf("Queue Full\n");
    }
  }

  cq_print(&cq);

  int value;

  cq_dequeue(&cq, &value);
  printf("Dequeued: %d\n", value);

  if (cq_peek(&cq, &value))
    printf("Front element: %d\n", value);

  cq_print(&cq);

  return 0;
}
