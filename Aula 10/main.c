#include <stdio.h>


/* Implementing a bubble sort algorithm */
int main() {

  int array[5] = {56, 35, 98, 10, 88};
  int i, j, k;

  printf("Before sorting: \n");
  for(i=0; i<5; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  for(i=0; i<5; i++) {
    for(j=0; j<5-i - 1; j++) {
      if(array[j] > array[j + 1]) {
        int temp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = temp;
      }
    }
  }

  printf("After sorting: \n");
  for(i=0; i<5; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
