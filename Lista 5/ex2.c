#include <stdlib.h>
#include <stdio.h>
#include "Arquivos/list.h"
#include <limits.h>

/* 
  Similarly to what was done on the previous exercise list,
  this exercise checks whether or not an element k is contained
  on a list l. This search must be done using recursion
 */
int in(List *l, int k) {

  if(l == NULL) {
    return 0;
  }	

  if(l->data == k) {
    return 1;
  }
  else {
    return in(l->next, k);
  }

}

int main() {

  List *l = NULL;
  int k;

  for (k = 0; k <= 5; k++) {
    l = insert_back (l, k);
  }

  printf("Lista = ");
  print (l);
  printf("\n");

  printf("In = %d\n", in(l,3));
  printf("In = %d\n", in(l,6));

  destroy (l);

  return 0;
}
