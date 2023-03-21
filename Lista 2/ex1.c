#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Arquivos/queue.h"

/*
  Para facilitar os testes, o usuário deve inserir junto da linha de comando
  com a invocação do programa, a quantidade de numeros da sequencia. Isso
  foi feito para facilitar o teste do exercício.

  Para atingir o resultado
*/

int main(int argc, char *argv[]) {

  // sequenceLength é lido diretamente do terminal durante a invocação do executavel
  int sequenceLength = atoi(argv[1]);
  int sequence[sequenceLength];
  int i;

  printf("A quantidade de elementos da sequencia randomica deve acompanhar a invocacao do executavel no terminal\n");
  printf("Sua sequencia aleatoria contara com %d numeros\n\n", sequenceLength);
  
  srand(sequenceLength);

  i = 0;
  while(i < sequenceLength) {
    sequence[i] = rand() % 100;
    i++;
  }

  printf("A sequencia de numeros gerados foi a sequinte: \n");
  printf("sequence = ");
  for(i=0; i<sequenceLength; i++) {
    printf("%d ", sequence[i]);
  }
  printf("\n\n");

  Queue *pares = create(sequenceLength);
  Queue *impares = create(sequenceLength);

  for(i=0; i<sequenceLength; i++) {

    if(sequence[i] % 2 == 0) {
      enqueue(pares, sequence[i]);
    }
    else {
      enqueue(impares, sequence[i]);
    }

  }

  // Mostrando ao usuário o resultado das duas filas:
  
  printf("Par - ");
  print(pares);

  printf("\nImpares - ");
  print(impares);

  /* 
    Para reduzir O, poderíamos ao passo que o numero
    randomico é gerado, já determinar caso ele é par
    ou impar e então já incorpora-lo a sua respectiva
    fila. A abordagem feita escolhida foi tal que o 
    entendimento do fluxo de execução estivesse otimizado.
  */

  return 0;

}