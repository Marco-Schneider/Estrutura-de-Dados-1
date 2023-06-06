#include "list.h"

List* add (List *lx, List *ly) {
  List *lz = create();	
  Node *tx = lx->tail;
  Node *ty = ly->tail;
  int soma = 0;
  int sobra = 0;

  /* Percorrendo as listas */
  while(tx != NULL && ty != NULL) {
    soma = tx->data + ty->data + sobra;
    sobra = soma / 10;
    soma = soma % 10;
    insert_front(lz, soma);
    tx = tx->prev;
    ty = ty->prev;
  }
  /* Caso X tenha mais algarismos que Y */
  while(tx != NULL) {
    soma = tx->data + sobra;
    sobra = soma / 10;
    soma = soma % 10;
    insert_front(lz, soma);
    tx = tx->prev;
  }
  /* Caso Y tenha mais algarismos que X */
  while(ty != NULL) {
    soma = ty->data + sobra;
    sobra = soma / 10;
    soma = soma % 10;
    insert_front(lz, soma);
    ty = ty->prev;
  }
  /* O que sobrar é colocado no algarismo mais significativo */
  if(sobra > 0) {
    insert_front(lz, sobra);
  }

  return lz;
}

int main () {
  
  /* Resultado esperado:
   * List (head-tail): 9 9        <- X
   * List (head-tail): 9 9 4 5    <- Y
   * List (head-tail): 1 0 0 4 4  <- X + Y
   * */

  int k;	

  List *lx = create ();
  int nx = 2;
  int x[] = {9,9};
  for (k = 0; k < nx; k++) 
    insert_back (lx, x[k]); 	  
  print_head_to_tail (lx);

  List *ly = create ();
  int ny = 4;
  int y[] = {9,9,4,5};
  for (k = 0; k < ny; k++) 
    insert_back (ly, y[k]); 	 
  print_head_to_tail (ly);

  List *lz = add (lx, ly);
  print_head_to_tail (lz);

  destroy (lx);
  destroy (ly);
  destroy (lz);
  return 0;
} 
