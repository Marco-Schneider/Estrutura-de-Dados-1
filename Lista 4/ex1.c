#include <stdio.h>
#include <stdlib.h>

#include "Arquivos/list.h"

/* This function receives a list and performs the sum of all of its elements*/
int sum(List *l) {
  
  List *t;
  int sum = 0;

  for(t=l; t!=NULL; t=t->next) {
    sum = sum + t->data;
  }

  return sum;
}

int main() {

  int k;
  List *l = NULL;

  for (k = 0; k <= 4; k++) 
    l = insert (l, k);

  for (k = 9; k >= 5; k--) 
    l = insert (l, k);

  print (l);

  printf("Sum = %d\n", sum(l));
  destroy (l);

  return 0;
}