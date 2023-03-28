#include <stdio.h>
#include <stdlib.h>

#include "Arquivos/list.h"

/* 
  This function receives two lists, A and B,
  it returns a merged list C. This resulting 
  list C is the merged result of A and B in
  ascendent order
*/
List* merge(List *A, List *B){

  List *C;
  List *t;

  int lowest = A->data;
  for(t=A; t!=NULL; t=t->next) {
    printf("%d\n", t->data);
  }
  print(t);
}

int main () {

  int k;
  List *A = NULL, *B = NULL;

  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);

  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);

  print (A);
  print (B);

  List *C = merge (A, B);

  print (C);
  destroy (C);

  return 0;
}
