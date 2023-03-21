#include "stack.h"

int main () {
  int tam = 6;
  Stack *s = create (tam);
  int i;
  for (i = 0; i < tam; i++) {
    push (s, rand()%10);
  }
  print (s);
  /*TERMINAR*/
  destroy (s);
}
