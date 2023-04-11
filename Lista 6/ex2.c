#include <stdio.h>

#include "Arquivos/list.h"

/**/
// List* insert_back (List *l, int elem) {

//   List *node = (List *)malloc(sizeof(List));
//   node->data = elem;

//   if(l == NULL) {
//     node->prev = NULL;
//     node->next = NULL;
//     return node;
//   } 

//   List *tail = l;
//   for(tail=l; tail->next != NULL; tail=tail->next) { }
//   tail->next = node;
//   node->prev = tail;

//   return l;
// }

int main() {

  List *A = NULL;
  
  A = insert_front(A, 2);
  print(A);
  A = insert_front(A, 3);
  print(A);
  A = insert_back(A, 6);
  print(A);

  return 0;
}