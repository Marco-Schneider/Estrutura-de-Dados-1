#include "Arquivos/utils.h"

/*Função para intercalar dois subvetores em um conjunto ordenado. 
 *{A} é o vetor de entrada, {l} é a esquerda (de left), 
 {m} é o meio (ou middle), {r} é a direita (de right),
 {O} é o vetor auxilar (de output). */
void merge (int A[], int l, int m, int r, int O[]) {
  int i = l;
  int j = m + 1;
  int k = l;
  while((i<=m) && (j<=r)) {
    if(A[i] <= A[j]) {
      O[k++] = A[i++];
    } else {
      O[k++] = A[j++];
    }
  }
  while(i <= m) {
    O[k++] = A[i++];
  }
  while(j <= r) {
    O[k++] = A[j++];
  }
  for(j=l; j <= r; j++) {
    A[j] = O[j];
  }
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int l, int r, int O[], int level) {
  if(l < r) {
    int m = (l + r)/2;

    for(int i=0; i<level; i++) {
      printf("  ");
    }
    printf("Merge-sort (%d, %d, %d)\n", l, m, r);
    merge_sort(A, l, m, O, level + 1);

    for(int i=0; i<level; i++) {
      printf("  ");
    }
    printf("Merge-sort (%d, %d, %d)\n", l, m, r);
    merge_sort(A, m+1, r, O, level + 1);

    for(int i=0; i<level; i++) {
      printf("  ");
    }
    printf("Intercalando = {");
    for(int i = l; i <= m; i++) {
      printf("%d", A[i]);
      if (i != m) {
        printf(", ");
      }
    }

    printf(", ");

    for(int i = m + 1; i <= r; i++) {
      printf("%d", A[i]);
      if (i != r) {
        printf(", ");
      }
    }
    printf("}\n");
    merge(A, l, m, r, O);
  }
}

int main (int argc, char *argv[]) {
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }
  int i;
  int n = atoi(argv[1]);;
  int *A = (int *)malloc(n * sizeof(int));
  int *O = (int *)malloc(n * sizeof(int)); /*array auxiliar*/
  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
    // A[i] = i;   /*valores em ordem crescente*/
    // A[i] = n-i; /*valores em ordem descrescente*/
    // A[i] = 0;   /*valores iguais*/
  }
  start = clock();
  // print (A, n, "Input");
  merge_sort (A, 0, n-1, O, 0);
  // print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  free (O);
  return 0;
}

