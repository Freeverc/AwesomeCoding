#include "stack.h"

int main(void) {
	Stack stack;
	double val;
	CreateStack(&stack, 10);
	Push(&stack, 5);
	Push(&stack, 6.5);
	Push(&stack, -3);
	Push(&stack, -8); 
	DisplayStack(&stack);
	if (Top(&stack, &val))
		printf("Top: %g\n", val); 
	Pop(&stack, &val); 
	if (Top(&stack, &val))
		printf("Top: %g\n", val); 
	while (!IsEmpty(&stack))
	{
		Pop(&stack, &val);
		printf("Top: %g\n", val); 
	}
	DestroyStack(&stack);
	DisplayStack(&stack); 
}