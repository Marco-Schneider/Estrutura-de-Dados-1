#include <stdio.h>
#include <stdlib.h>

#include "Arquivos/stack.h"

int parser (char *c) {

  Stack *s = create(strlen(c));
  int i = 0;

  while(c[i] != '\0') {
    
    switch(c[i]) {
      case '(':
        push(s, c[i]);
        break;
      case '[':
        push(s, c[i]);
        break;
      case ')':
        if(get_peek(s) == '(')
          pop(s);
        break;
      case ']':
        if(get_peek(s) == '[')
          pop(s);
        break;
    }

    i++;    
  }

  if(empty(s)) {
    destroy(s);
    return 1;
  }
  else {
    destroy(s);
    return 0;
  }

}

int main () {

  char *c = "( ( ) [ ( ) ] )";
  // char *c = "( [ ) ]";
  //char *c = "( ) [ ]";
  //char *c = "( [ ]";
  // char *c = ") (";

  if (parser(c)) 
    printf("true  (bem formada)\n");
  else  
    printf("false (mal formada)\n");
  
  return 0;

}
