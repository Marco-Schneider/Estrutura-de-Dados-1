#include "Arquivos/list.h"

List *create_circular(List *head) {

  if(head == NULL) {
    return head;
  }

  List *tail = head;
  while(tail->next != NULL) { 
    tail = tail->next;
  }

  tail->next = head;
  head->prev = tail;

  return head;
}

int is_circular (List *head) {

  if(head == NULL || head->next == NULL) {
    return 0;
  }

  List *tail = head;
  while(tail->next != NULL) {
    tail = tail->next;
    if(tail == head) {
      return 1;
    }
  }
  return 0;
}

int main () {
  int i;	
  int n = 4;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  printf("Is circular: %d\n", is_circular(l));
  l = create_circular(l);
  printf("Is circular: %d\n", is_circular(l));
  return 0;
} 