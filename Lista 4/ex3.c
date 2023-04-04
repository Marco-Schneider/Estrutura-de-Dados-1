#include <stdio.h>
#include <stdlib.h>

#include "Arquivos/list.h"

/* 
  This function receives two lists, A and B,
  it returns a merged list C. This resulting 
  list C is the merged result of A and B in
  ascendent order
*/
List* merge(List *A, List *B){

  List *C = NULL;
  List *tail = NULL;
  List *head = NULL;
  List *helper = NULL;

  /* 'Copying' A to C */
  C = A;

  /* 'Copying' B to C*/
  tail = A;
  while(tail->next != NULL) {
    tail =  tail->next;
  }
  tail->next = B;
  /* ------- */

  /* Now that we have it all set, we can perfom a sort*/
  /* 
    The complexity here is O(n^2) - There are certainly more effecient ways to solve this,
    however, this was, as per the time of solving this exercise, this was the only implementation that worked
  */
  int temp;
  for(head=C; head!=NULL; head=head->next) {
    for(helper=head->next; helper!=NULL; helper=helper->next){
      if(head->data > helper->data) {
        temp = head->data;
        head->data = helper->data;
        helper->data = temp;
      }
    }
  }
  
  return C;
}

int main () {

  int k;
  List *A = NULL, *B = NULL;

  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);

  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);

  print (A);
  print (B);

  List *C = merge (A, B);

  print(C);

  destroy (C);

  return 0;
}
