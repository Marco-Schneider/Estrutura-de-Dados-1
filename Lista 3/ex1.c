#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Arquivos/stack.h"

int main() {

  srand(time(NULL));

  int size = 6;

  Stack *stack1 = create(size);
  Stack *stack2 = create(size);

  for (int i=0; i<size; i++) {
    push (stack1, rand()%10);
  }
  print (stack1);
  
  // Searching elements through the first stack
  while(!empty(stack1)) {

    // Gathering the odd elements
    if(get_peek(stack1) % 2 != 0) {
      push(stack2, pop(stack1));
    }
    else {
      pop(stack1);
    }

  }

  // Moving the elements back to the first stack
  while(!empty(stack2)) {
    push(stack1, pop(stack2));
  }

  printf("After the operation: \n");
  print(stack1);

  destroy(stack1);
  destroy(stack2);

  return 0;
  
}