#include "Arquivos/list.h"
#include <stdio.h>

int max_itr(List *l) {
  int maior;
  maior = l->data;

  if(l == NULL) {

  }

  while(l->next != NULL) {
    if(l->data > maior) {
      maior = l->data;
    }
    l = l->next;
  }
  return maior;
}

int max_rec(List *l) {
  if(l== NULL) {
    return -INT_MAX;
  }
  else {
    int maior = l->data;
    int proximo = max_rec(l->next);
    if(maior > proximo) {
      return maior;
    }
    else {
      return proximo;
    }
  }
}

int main() {

  int k;
  List *l = NULL;

  for (k = -9; k <= 4; k++) 
    l = insert (l, k);

  for (k = 25; k >= 5; k--) 
    l = insert (l, k);

  print (l);

  printf("The biggest number is: %d\n", max_itr(l));
  printf("The biggest number is: %d", max_rec(l));

  return 0;
}