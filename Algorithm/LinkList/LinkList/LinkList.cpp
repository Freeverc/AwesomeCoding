#include "LinkList.h"

/***************************************
	implement all the functions here
****************************************/
bool IsEmpty(Node* head)
{
	if (head == NULL)
	{
		return 1;
	}
	return 0;
}

Node* InsertNode(Node** phead, int index, double x)
{
	Node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = x;
	Node* currentNode = *phead;
	if (index == 0)
	{
		newNode->next = currentNode;
		*phead = newNode;
		return newNode;
	}
	index--;
	while (index > 0)
	{
		currentNode = currentNode->next;
		index--;
	}
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	return newNode;
}

int FindNode(Node* head, double x)
{
	int index = 1;
	Node* currentNode = head;
	while (currentNode != NULL)
	{
		if (currentNode->data == x)
			return index;
		currentNode = currentNode->next;
		++index;
	}
	return 0;
}

int DeleteNode(Node** phead, double x)
{
	Node* currentNode = *phead;
	Node* deleteNode = currentNode;
	int index = 0;
	if (currentNode == NULL)
		return index;
	else if (currentNode->data == x)
	{
		*phead = currentNode->next;
		free(deleteNode);
		++index;
		return index;
	}
	while(currentNode->next != NULL)
	{
		if (currentNode->next->data == x)
		{
			deleteNode = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(deleteNode);
			return index;
		}
		currentNode = currentNode->next;
		++index;
	}
	return 0;

}

void DisplayList(Node* head)
{
	Node* currentNode = head;
	while (currentNode != NULL)
	{
		printf("%lf ", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
	return;
}

void DestroyList(Node** phead)
{
	Node* currentNode = *phead;
	Node* deleteNode;
	*phead = NULL;
	while (currentNode!= NULL)
	{
		deleteNode = currentNode;
		currentNode = currentNode->next;
		free(deleteNode);
	}
	return;
}

int main()
{
	/* build a empty linklist;*/
	Node* head = NULL;

	/* build a non-empty linklist;*/
	//Node* head = (struct node*)malloc(sizeof(struct node));
	//head->next = NULL;
	//head->data = 0;
	
	// input data
	//int len = 4, i = 1;
	//double data;
	//while (i<len)
	//{
	//	scanf("%lf", &data);
	//	InsertNode(&head, i, data);
	//	i++;
	//}
	int isEmp = IsEmpty(head);
	DisplayList(head);
	printf("The link is Empty: %d \n", isEmp);
	for (int i = 0; i < 5; i++)
		InsertNode(&head, i, i);
	isEmp = IsEmpty(head);
	printf("The link is Empty: %d \n", isEmp);
	printf("The link is :\n");
	DisplayList(head);
	// find a node in the linklist
	for (int i = 0; i < 7; i += 2) {
		int idx = FindNode(head, i);
		if (idx > 0)
			printf("%d is at position %d.\n", i, idx);
		else
			printf("%d is not in the list.\n", i);
	}

	// delete a node in the linklist
	DeleteNode(&head,2);
	DisplayList(head);
	// destroy the link list
	DestroyList(&head);
	DisplayList(head);
}