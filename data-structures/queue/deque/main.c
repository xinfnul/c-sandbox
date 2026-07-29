#include "deque.h"

#include <stdio.h>

int main(void) {
  Deque dq;

  deque_init(&dq);

  deque_push_back(&dq, 10);
  deque_push_back(&dq, 20);
  deque_push_front(&dq, 5);
  deque_push_front(&dq, 1);

  printf("Front: %d\n", deque_front(&dq));
  printf("Back : %d\n", deque_back(&dq));

  printf("Pop front: %d\n", deque_pop_front(&dq));
  printf("Pop back : %d\n", deque_pop_back(&dq));

  printf("Size: %d\n", deque_size(&dq));

  deque_clear(&dq);

  return 0;
}
