#include "calculator.h"

struct List *new_list(void)
{
	struct List *newList = (struct List*)malloc(sizeof(struct List));
	*newList = (struct List){NULL,0};
	return newList;
}

struct Node *new_node(void *value)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	*newNode = (struct Node){NULL,value};
	return newNode;
}

void add_first(struct List *list,void *value)
{
	void *newValue = new_value(value);
	struct Node *newNode = new_node(newValue);
	newNode->next = list->first;
	list->first = newNode;
	list->size++;
}

void remove_first(struct List *list)
{
	struct Node *removeNode = list->first;
	if (removeNode != NULL)
	{
		list->first = removeNode->next;
		free(removeNode->value);
		free(removeNode);
		list->size--;
	}
}

void remove_list(struct List *list)
{
	while (list->size > 0)
	{
		remove_first(list);
	}
	free(list);
}

void *new_value(void *value)
{
	void *newValue = malloc(1);
	*(double*)newValue = *(double*)value;
	return newValue;
}

void *get_first(struct List *list)
{
	if (list->first != NULL)
	{
		return list->first->value;
	}
	return NULL;
}
