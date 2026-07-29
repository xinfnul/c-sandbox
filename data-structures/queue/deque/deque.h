#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct {
  Node *front;
  Node *rear;
  int size;
} Deque;

void deque_init(Deque *dq);

bool deque_is_empty(Deque *dq);
int deque_size(Deque *dq);

void deque_push_front(Deque *dq, int value);
void deque_push_back(Deque *dq, int value);

int deque_pop_front(Deque *dq);
int deque_pop_back(Deque *dq);

int deque_front(Deque *dq);
int deque_back(Deque *dq);

void deque_clear(Deque *dq);

#endif
