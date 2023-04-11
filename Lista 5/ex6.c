// #include <stdlib.h>
// #include <stdio.h>

// #include "Arquivos/list.h"


// int max(List *l) {

//   List *head;
//   List *helper;

//   head = l;
//   helper = head;

//   if(l != NULL) {
//     if(head->data > helper-> data) {
//       return head->data;
//     }
//     return max(l);
//   }

// }

// int main() {

//   List *l = NULL;
//   int k;

//   for (k = 5; k <= 9; k++) {
//     l = insert_back (l, k);
//   }
//   for (k = 4; k >= 0; k--) {
//     l = insert_back (l, k);
//   }

//   printf("The highest number on the list is: %d\n", max(l));

//   return 0;
// }