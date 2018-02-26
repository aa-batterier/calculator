#include "stack_calculator.h"

struct List *new_list(void)
{
	struct List *newList = (struct List*)malloc(sizeof(struct List));
	*newList = (struct List){NULL,0};
	return newList;
}

struct Node *new_node(void *data)
{
	struct Node *newNode = (struct Node)malloc(sizeof(struct Node));
	*newNode = (struct Node){NULL,data};
	return newNode;
}

void add_first(struct List *list,void *data)
{
	struct Node *newNode = new_node(data);
	newNode->next = list->first;
	list->first = newNode->next;
	list->size++;
}

void remove_first(struct List *list)
{
	struct Node *removeNode = list->first;
	if (removeNode != NULL)
	{
		list->first = removeNode->next;
		free(removeNode);
		list->size--;
	}
}
