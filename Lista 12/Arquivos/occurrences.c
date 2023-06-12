#include "utils.h"

/* */
int binary_search (int *A, int n, int key, int explore_left) {
  int left = 0, right = n - 1;
  int result = -1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (A[middle] == key) {
      result = middle;
      if (explore_left) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    } else if (A[middle] < key) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return result;
}

/* */
int find_occurrences (int *A, int n, int target) {
  int first = binary_search(A, n, target, 1);
  if (first == -1) {
    return 0;
  }
  int last = binary_search(A, n, target, 0);
  return last - first + 1;	
}

/* */
int main () {
  int i, n = 10;
  int targets[] = {0,2,8,5,6,9};
  int A[] = {2,5,5,5,6,6,8,9,9,9};
  print (A, n, "Input");
  for (i = 0; i < 6; i++) {
    int oc = find_occurrences (A, n, targets[i]);
    if (oc != NOT_FOUND)
      printf("Target %d found %d times.\n", targets[i], oc);
    else
      printf("Target %d not found.\n", targets[i]);
  }  
  return 0;
}
