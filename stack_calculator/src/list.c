#include "calculate.h"

struct List *new_list(void)
{
	struct List *newList = (struct List*)malloc(sizeof(struct List));
	*newList = (struct List){NULL,0};
	return newList;
}

struct Node *new_node(int data)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	*newNode = (struct Node){NULL,data};
	return newNode;
}

void add_first(struct List *list,int data)
{
	struct Node *newNode = new_node(data);
	newNode->_next = list->_first;	
	list->_first = newNode;
	list->_size++;
}

void remove_first(struct List *list)
{
	assert(list->_first != NULL);
	struct Node *removeNode = list->_first;
	list->_first = removeNode->_next;
	free(removeNode);
	list->_size--;
}

int get_first(struct List *list)
{
	assert(list->_first != NULL);
	return list->_first->_data;
}

void remove_list(struct List *list)
{
	assert(list != NULL);
	while (list->_size)
		remove_first(list);
	free(list);
}
