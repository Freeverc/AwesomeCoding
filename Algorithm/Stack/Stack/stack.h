#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

class Stack
{
public:
	int size;
	double* values;
	int top;
	Stack();
	Stack(int size);
	~Stack();

};


bool CreateStack(Stack *stack, int size);
bool IsEmpty(Stack *stack);
bool IsFull(Stack *stack);
bool Top(Stack *stack, double * x);
bool Push(Stack *stack, double x);
bool Pop(Stack *stack, double * x);
void DisplayStack(Stack *stack);
void DestroyStack(Stack *stack);
