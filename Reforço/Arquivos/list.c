#include "list.h"

/**/
List* create () {
  List *l = (List *)malloc(sizeof(List));
  l->head = NULL;
  l->tail = NULL;
  return l;
}

/**/
void insert_front (List *l, int elem) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = elem;
  n->prev = NULL;
  if (l->head != NULL) {
    n->next = l->head;
    l->head->prev = n;
  }  
  else { 
    n->next = NULL;
    l->tail = n;
  }  
  l->head = n;
}

/**/
void insert_back (List *l, int elem) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = elem;
  n->next = NULL;
  if (l->tail != NULL) {
    n->prev = l->tail;
    l->tail->next = n;
  }
  else {
    n->prev = NULL;
    l->head = n;
  }
  l->tail = n;
}

/**/
void remove_front (List *l) {
  if (l->head != NULL) {
    Node *n = l->head->next; 	 
    free (l->head);
    if (n != NULL) 
       n->prev = NULL;
    else
       l->tail = NULL;	    
    l->head = n;
  }  
}

/**/
Node* search (List *l, int k) {
  if (l != NULL) {
    Node *n = l->head;	   
    while (n != NULL) {
      if (n->data == k) 
        return n;
      n = n->next;
    }  
  }
  return NULL;  
}

/**/
void print_head_to_tail (List *l) {
  Node *tmp;
  printf("head_to_tail: ");
  for (tmp = l->head; tmp != NULL; tmp = tmp->next)
    printf("%d ", tmp->data);
  printf("\n");  
}

/**/
void print_tail_to_head (List *l) {
  Node *tmp;
  printf("tail_to_head: ");
  for (tmp = l->tail; tmp != NULL; tmp = tmp->prev)
    printf("%d ", tmp->data);
  printf("\n");  
}

/**/
void destroy (List *l) {
  if (l != NULL) {	
    Node *h = l->head;	
    while (h != NULL) {
      Node *t = h->next; 
      free (h); 
      h = t;    
    }
  }  
}
