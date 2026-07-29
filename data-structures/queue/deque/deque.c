#include "deque.h"

#include <stdio.h>
#include <stdlib.h>

static Node *create_node(int value) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  node->data = value;
  node->prev = NULL;
  node->next = NULL;

  return node;
}

void deque_init(Deque *dq) {
  dq->front = NULL;
  dq->rear = NULL;
  dq->size = 0;
}

bool deque_is_empty(Deque *dq) { return dq->size == 0; }

int deque_size(Deque *dq) { return dq->size; }

void deque_push_front(Deque *dq, int value) {
  Node *node = create_node(value);

  if (deque_is_empty(dq)) {
    dq->front = dq->rear = node;
  } else {
    node->next = dq->front;
    dq->front->prev = node;
    dq->front = node;
  }

  dq->size++;
}

void deque_push_back(Deque *dq, int value) {
  Node *node = create_node(value);

  if (deque_is_empty(dq)) {
    dq->front = dq->rear = node;
  } else {
    node->prev = dq->rear;
    dq->rear->next = node;
    dq->rear = node;
  }

  dq->size++;
}

int deque_pop_front(Deque *dq) {
  if (deque_is_empty(dq)) {
    fprintf(stderr, "Deque is empty\n");
    exit(EXIT_FAILURE);
  }

  Node *temp = dq->front;
  int value = temp->data;

  dq->front = temp->next;

  if (dq->front)
    dq->front->prev = NULL;
  else
    dq->rear = NULL;

  free(temp);
  dq->size--;

  return value;
}

int deque_pop_back(Deque *dq) {
  if (deque_is_empty(dq)) {
    fprintf(stderr, "Deque is empty\n");
    exit(EXIT_FAILURE);
  }

  Node *temp = dq->rear;
  int value = temp->data;

  dq->rear = temp->prev;

  if (dq->rear)
    dq->rear->next = NULL;
  else
    dq->front = NULL;

  free(temp);
  dq->size--;

  return value;
}

int deque_front(Deque *dq) {
  if (deque_is_empty(dq)) {
    fprintf(stderr, "Deque is empty\n");
    exit(EXIT_FAILURE);
  }

  return dq->front->data;
}

int deque_back(Deque *dq) {
  if (deque_is_empty(dq)) {
    fprintf(stderr, "Deque is empty\n");
    exit(EXIT_FAILURE);
  }

  return dq->rear->data;
}

void deque_clear(Deque *dq) {
  while (!deque_is_empty(dq)) {
    deque_pop_front(dq);
  }
}
