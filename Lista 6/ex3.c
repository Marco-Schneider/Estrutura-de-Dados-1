#include <stdio.h>

#include "Arquivos/list.h"

List *create_circular(List *head) {

  if(head == NULL) {
    return head;
  }

  List *tail = head;
  for(tail=head; tail->next != NULL; tail->next) { }

  tail->next = head;
  head->prev = tail;

  return head;
}

int main() {

  List *A = NULL;
  
  A = insert_front(A, 2);
  print(A);
  A = insert_front(A, 3);
  print(A);
  A = insert_front(A, 6);
  print(A);

  create_circular(A);
  print(A);

  return 0;
}