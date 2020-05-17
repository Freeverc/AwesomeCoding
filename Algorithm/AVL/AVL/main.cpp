#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"


void main() 
{
  Node * root = NULL;    
  
  int ins[]={16, 10, 21, 5, 12, 18, 24, 2, 8, 11, 15, 19, 23, 31, 1, 6, 9, 13, 22, 7};
  int len = 20, x;
  for(int i=0; i<len; i++){
	  printf("\nAfter inserting key %d..\n", ins[i]);
	  insertNode(&root,ins[i]);
	  printTree(root);
  }
  printf("\nInsert a new node (+ to insert, - to delete, 0 to exit): ");
  scanf("%d",&x);
  while(x){
	  if(x > 0 )
		  insertNode(&root,x);
	  else
		  free(deleteNode(&root,-x));
	  printTree(root);
	  printf("\nInsert a new node (+ to insert, - to delete, 0 to exit): ");
	  scanf("%d",&x);
  }
  destroyTree(root);
}