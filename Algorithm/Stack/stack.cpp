#include "stack.h"

// costruction
Stack::Stack()
{
	this->top = -1;
	this->size = 0;
}
Stack::Stack(int stackSize)
{
	this->top = -1;
	this->size = stackSize;
	this->values = (double*)malloc(sizeof(double)*stackSize);
}
// destruction
Stack::~Stack()
{
	//printf("destruced!\n");
}
//
bool CreateStack(Stack *stack, int size)
{
	if (size <= 0)
		return false;
	*stack = Stack(size);
	return true;
}
bool IsEmpty(Stack *stack)
{
	if ((NULL == stack)||(stack->top <= -1))
		return true;
	return false;
}
bool IsFull(Stack* stack)
{
	if ((NULL == stack)||(stack->top <= stack->size))
		return false;
	return true;
}

bool Top(Stack *stack, double * x)
{
	if (IsEmpty(stack))
		return false;
	*x = stack->values[stack->top];
	return true;
}

bool Push(Stack* stack, double x)
{
	if (IsFull(stack))
		return false;
	++stack->top;
	stack->values[stack->top] = x;
	return true;
}
bool Pop(Stack* stack, double* x)
{
	if (IsEmpty(stack))
		return false;
	*x = stack->values[stack->top];
	stack->top--;
	return true;
}
void DisplayStack(Stack* stack)
{
	if (IsEmpty(stack))
		return;
	for (int i = 0;i<=stack->top;i++)
	{
		printf("%lf ", stack->values[i]);
	}
	printf("\n");
	return;
}
void DestroyStack(Stack* stack)
{
	if (IsEmpty(stack))
		return;
	delete stack;
	return;
}