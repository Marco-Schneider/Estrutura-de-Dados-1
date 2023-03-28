/*
  References:
  https://www.scaler.com/topics/polish-notation-in-data-structure/
  https://www.tutorialspoint.com/data_structures_algorithms/expression_parsing.htm
  
  *A better explanation on the subject regarding RPN and stacks*
  https://www.youtube.com/watch?v=7ha78yWRDlE&ab_channel=Computerphile

  a + b => Infix
  a b + => Postfix

  a + b * c => Infix
  a b c * + => Postfix

  (a + b) * c => Infix
  a b + c * => Postfix
*/
#include <stdio.h>
#include <stdlib.h>

#include "Arquivos/stack.h"

void compute_polish_expression(char *c) {

  Stack *s = create(strlen(c));
  int i = 0;

  while (c[i] != '\0') {

    if(c[i] >= '0' && c[i] <= '9')
      push(s, c[i] - '0');
    
    switch(c[i]) {
    case '+':
      push(s, pop(s) + pop(s));
      break;
    case '-':
      push(s, pop(s) - pop(s));
      break;
    case '/':
      push(s, pop(s) / pop(s));
      break;
    case '*':
      push(s, pop(s) * pop(s));
      break;
    }
    i++;
  }
  printf("Result: %d", get_peek(s));
  printf("\n");
  destroy(s);
}

int main () {

  char *c = "9 0 1 + 2 3 * * +";

  compute_polish_expression(c);

  return 0;
}