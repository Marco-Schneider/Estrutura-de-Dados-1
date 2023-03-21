#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Arquivos/pqueue.h"

/*
  Essa função retorna se um dado par ordenado (i, j)
  representativo de um elemento da Matriz M está ou não
  dentro dos limites da matriz, visto que tanto i quanto j
  são maiores que 0 e menores que n.

  Retorna 0 caso (i, j) esteja fora dos limites
  Retorna 1 caso (i, j) esteja dentro dos limites
*/
int inside (int i, int j, int n) {
  if ((i < 0) || (j < 0) || (i >= n) || (j >= n))
    return 0;
  return 1;    
}

void print_matrix (char M[][10], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%c ", M[i][j]);
    }
    printf("\n");
  }   
}

/*
  Dado um elemento da matriz M onde há a ocorrência de um "*",
  precisamos checar nas oito direções adjacentes a esse ponto
  para certificar que se trata ou não de uma outra componente
  da ilha.
  
  Considerando:
  ^ 
  |
  |
  y 
   x -->


*/
void conquer (char M[][10], int i, int j, int n, int nlabel) {

  Queue *q = create((n*n)+1);
  enqueue (q, (point){i,j});
  M[i][j] = ' ';

  while (!empty(q)) {
    point p = dequeue (q);
    int x = p.x, y = p.y;

    // 1- Checando o Norte
    if(inside(x, y+1, n) && M[x][y+1] == '*') {
      enqueue(q, (point){x, y+1});
      M[x][y+1] = ' ';
    }

    // 2- Checando o Nordeste
    if(inside(x+1, y+1, n) && M[x+1][y+1] == '*') {
      enqueue(q, (point){x+1, y+1});
      M[x+1][y+1] = ' ';
    }

    // 3- Checando o Leste
    if(inside(x+1, y, n) && M[x+1][y] == '*') { 
      enqueue(q, (point){x+1, y});
      M[x+1][y] = ' ';
    }

    // 4- Checando o Sudeste
    if(inside(x+1, y-1, n) && M[x+1][y-1] == '*') { 
      enqueue(q, (point){x+1, y-1});
      M[x+1][y-1] = ' ';
    }

    // 5- Checando o Sul
    if(inside(x, y-1, n) && M[x][y-1] == '*') { 
      enqueue(q, (point){x, y-1});
      M[x][y-1] = ' ';
    }
    
    // 6- Checando o Sudoeste
    if(inside(x-1, y-1, n) && M[x-1][y-1] == '*') { 
      enqueue(q, (point){x-1, y-1});
      M[x-1][y-1] = ' ';
    }

    // 7- Checando o Oeste
    if(inside(x-1, y, n) && M[x-1][y] == '*') {
      enqueue(q, (point){x-1, y});
      M[x-1][y] = ' ';
    }

    // 8- Checando o Noroeste
    if(inside(x-1, y+1, n) && M[x-1][y+1] == '*') {
      enqueue(q, (point){x-1, y+1});
      M[x-1][y+1] = ' ';
    }

  }

  destroy (q); 

}

int count_islands (char M[][10], int n) {
  int i, j, sum = 0;	
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (M[i][j] == '*') {
	      sum++;
        conquer (M, i, j, n, sum);     
      }	      
    }	     
  }
  return sum;
}

int main () {
 
  int n = 10; 

  char M[][10] = 
    { {'*',' ','*',' ',' ',' ','*','*','*','*'}, 
      {' ',' ','*',' ','*',' ','*',' ',' ',' '},	    
      {'*','*','*','*',' ',' ','*',' ',' ',' '},
      {'*',' ',' ','*',' ',' ',' ',' ',' ',' '},
      {'*','*','*','*',' ',' ',' ','*','*','*'},
      {' ','*',' ','*',' ',' ','*','*','*','*'},
      {' ',' ',' ',' ',' ','*','*','*',' ',' '},
      {' ',' ',' ','*',' ',' ','*','*','*',' '},
      {'*',' ','*',' ','*',' ',' ','*',' ',' '},
      {'*','*','*','*',' ',' ',' ','*','*','*'} 
    } ;

  print_matrix (M, n);
  printf("Numero de ilhas: %d\n", count_islands (M, n));

  return 0; 
}