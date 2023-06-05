#include "utils.h"

void counting_sort (FILE *f, int range) {
  int i, j, c, total = 0;
  int *C = (int *)malloc((range+1) * sizeof(int));

  for (i = 0; i <= range; i++) {
    C[i] = 0;
  }

  while ((c = fgetc(f)) != EOF) {
    if (c >= 'a' && c <= 'z') {
      C[c - 'a']++;
      total++;
    }
  }

  for (i = 0; i <= range; i++) {
    float frequency = (float) C[i] / total;
    printf("%c:  %6d  %.4f\n", 'a' + i, C[i], frequency);
  }

  free(C);
}

int main (int argc, char *argv[]) {

  FILE *f = fopen("livros/livro_pt.txt", "r");

  int range = 25;

  counting_sort (f, range);
  
  fclose (f);

  return 0;
}

