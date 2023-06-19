#include <stdio.h>
#include <stdlib.h>
#include "Arquivos/utils.h"

void bubble_sort_bidirecional(int *A, int n) {
  int i, j, k;

  for(i=0; i<n; i++) {
    for(j=0; j< n - i - 1; j++) {
      if(A[j] > A[j + 1]) {
        int temp = A[j + 1];
        A[j + 1] = A[j];
        A[j] = temp;
      }
    }
    for(k=n-i-1; k>0; k--) {
      if(A[k] < A[k-1]) {
        int temp = A[k-1];
        A[k-1] = A[k];
        A[k] = temp;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }

  int i;
  int n = atoi(argv[1]);;
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
  }  

  start = clock();
  print(A, n, "Input");
  bubble_sort_bidirecional(A, n);
  print(A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}