#include <stdlib.h>
#include <stdio.h>

#include "Arquivos/list.h"

List* merge(List *A, List *B) {

  List *C = NULL;

  if(A == NULL) {
    return B;
  }
  else if(B == NULL) {
    return A;
  }

  /* Concatenating the two lists */
  if(A != NULL && B != NULL) {
    if(A->data <= B->data) {
      C = A;
      A->next = merge(A->next, B);
    }
    else {
      C = B;
      B->next = merge(A, B->next);
    }
  }

  /* 
    Sorting the concatenated list, similarly to what was done before
   */
  for(List *i = C; i != NULL; i = i->next) {
    for(List *j = i->next; j != NULL; j = j->next) {
      if(i->data > j->data) {
        int temp = i->data;
        i->data = j->data;
        j->data = temp;
      }
    }
  }

  return C;
}

int main() {

  List *A = NULL, *B = NULL;

  for (int k = 10; k >= 0; k -= 2) {
    A = insert_back (A, k);
  }

  for (int k = 19; k >= 0; k -= 2) {
    B = insert_back (B, k);
  }

  printf("A: ");
  print(A);

  printf("\nB: ");
  print(B);

  List *C = merge (A, B);

  printf("\nC: ");
  print(C);
  printf("\n");

  destroy(C);

  return 0;
}