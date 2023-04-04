#include <stdlib.h>
#include <stdio.h>
#include "Arquivos/list.h"

/* 
  This function receives a lista l and return the
  sum of its elements. This sum is made through recursion.
  In this sense the idea here to is call the sum function
  multiple times
 */
int sum(List *l) {
  
  if(l != NULL) {
    return l->data + sum(l->next);
  }
  else {
    return 0;
  }

}

int main() {

  List *l = NULL;
  int k;

  for (k = 5; k <= 9; k++) {
    l = insert_back (l, k);
  }
  for (k = 4; k >= 0; k--) {
    l = insert_back (l, k);
  }

  printf("Lista = ");
  print (l);
  printf("\n");

  printf("Sum = %d\n", sum(l));
  destroy (l);

  return 0;
}
