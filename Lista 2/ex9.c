#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Arquivos/queue.h"

/*
  Dados três carreteis aleatórios, a serem gerados a 
  randomicante, simularemos o movimento dos carreteis com
  os métodos queue() e dequeue().

  Além da disposição aleatoria dos elementos no carretel,
  a quantidade de giros também será randomica.

  No final, o programa indica ao usuario se ele ganhou ou não
  e pergunta se o usuario que tentar novamente.

*/

void shuffle(int array[], int length) {

  srand(time(NULL));

  for(int i=0; i<length; i++) {

    int swapIndex = rand() % length;
    int temp = array[i];

    array[i] = array[swapIndex];
    array[swapIndex] = temp;

  }

}

int main() {

  int reelNumbers[] = {1, 2, 3, 4, 5,
                       6, 7, 8, 9};
  int spins;
  char continuePlaying = 'Y';

  Queue *reel_1 = create(10);
  Queue *reel_2 = create(10);
  Queue *reel_3 = create(10);

  shuffle(reelNumbers, 9);
  for(int i=0; i<9; i++) {
    enqueue(reel_1, reelNumbers[i]);
  }

  shuffle(reelNumbers, 9);
  for(int i=0; i<9; i++) {
    enqueue(reel_2, reelNumbers[i]);
  }

  shuffle(reelNumbers, 9);
  for(int i=0; i<9; i++) {
    enqueue(reel_3, reelNumbers[i]);
  }

  printf("Before the wheel is spun\n\n");
  print(reel_1);
  print(reel_2);
  print(reel_3);

  while(continuePlaying == 'Y') {

    spins = rand() % 9;
    printf("\n 1) There will be %d spin(s)\n", spins);
    for(int i=0; i<spins; i++) {
      enqueue(reel_1, dequeue(reel_1));
    }
    spins = rand() % 9;
    printf("\n 2) There will be %d spin(s)\n", spins);
    for(int i=0; i<spins; i++) {
      enqueue(reel_2, dequeue(reel_2));
    }
    spins = rand() % 9;
    printf("\n 3) There will be %d spin(s)\n", spins);
    for(int i=0; i<spins; i++) {
      enqueue(reel_3, dequeue(reel_3));
    }

    printf("\nAfter the wheel is spun\n");
    print(reel_1);
    print(reel_2);
    print(reel_3);

    if(front(reel_1) == front(reel_2) && front(reel_2) == front(reel_3)) {
      printf("\n\nGANHOU!!\n");
      continuePlaying = 'N';
    }
    else {
      printf("Seems you're out of luck, wanna try again? (Y) or (N)\n");
      fflush(stdin);
      scanf("%c", &continuePlaying);
    }

  }

  return 0;

}