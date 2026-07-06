#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

void initQueue(Queue *q) {
  q->front = NULL;
  q->rear = NULL;
}

bool isEmpty(Queue *q) { return q->front == NULL; }

void enqueue(Queue *q, int value) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }

  node->data = value;
  node->next = NULL;

  if (isEmpty(q)) {
    q->front = q->rear = node;
  } else {
    q->rear->next = node;
    q->rear = node;
  }
}

int dequeue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue Underflow\n");
    return -1;
  }

  Node *temp = q->front;
  int value = temp->data;

  q->front = q->front->next;

  if (q->front == NULL)
    q->rear = NULL;

  free(temp);
  return value;
}

int peek(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue Underflow\n");
    return -1;
  }

  return q->front->data;
}

void displayQueue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue Underflow\n");
    return;
  }

  Node *current = q->front;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void freeQueue(Queue *q) {
  while (!isEmpty(q)) {
    dequeue(q);
  }
}

int main(void) {
  Queue q;

  initQueue(&q);

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);

  printf("Queue: ");
  displayQueue(&q);

  printf("Front: %d\n", peek(&q));

  printf("Dequeued: %d\n", dequeue(&q));
  displayQueue(&q);

  freeQueue(&q);

  return 0;
}
