#include "list.h"

/* */
List* merge (List *A, List *B) {
  /*Terminar.*/	
}

/* */
int main () {
  int k;
  List *A = NULL;
  for (k = 0; k <= 14; k += 2) {
    A = insert_back (A, k);
  }
  printf("Lista = ");
  print (A);
  printf("\n");

  List *B = NULL;
  for (k = 1; k <= 9; k += 2) {
    B = insert_back (B, k);
  }
  printf("Lista = ");
  print (B);
  printf("\n");

  List *C = merge (A, B);
  printf("Lista = ");
  print (C);
  printf("\n");

  destroy (C);
  return 0;
}


