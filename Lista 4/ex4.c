#include <stdio.h>
#include <stdlib.h>

#include "Arquivos/list.h"

/* This function receives a list and returns its number of elements */
int size(List *l){

  List *t;
  int numberOfElements = 0;

  for(t=l; t!=NULL; t=t->next) {
    numberOfElements += 1;
  }

  return numberOfElements;
}

int main() {

  int tam = 10;
  List *l = NULL;

  for (int i = 0; i < tam; i++) 
  l = insert (l, i);

  print(l);
  printf("A lista possui %d elementos!\n", size(l));
  destroy(l);

  return 0;
}