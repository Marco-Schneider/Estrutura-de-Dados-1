#include <stdlib.h>
#include <stdio.h>

#include "Arquivos/list.h"

/*
  This function receives a List l and returns
  its size. This function must be recursive
*/
int size(List *l) {

  if(l != NULL) {
    return 1 + size(l->next);
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

  printf("The list has %d elements\n", size(l));

  destroy(l);

  return 0;
}