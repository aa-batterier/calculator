/*
 * Information about sourcedevelopment.
 * -------------------------------------
 *  Initial creator: Andreas Johansson.
 *  Date created: 21-04-2018
 *  Last updated by: Andreas Johansson.
 *  Date for update: 21-04-2018
 */

/*
 * File: list.c 
 * --------------
 *  Containes the functions which controlls and 
 *  creates the list/stack.
 */

#include "calculator.h"

/*
 * Function: new_list
 * Usage: Creates a new list.
 * ---------------------------
 */
struct List *new_list(void)
{
	struct List *newList = (struct List*)malloc(sizeof(struct List));
	*newList = (struct List){NULL,0};
	return newList;
}

/*
 * Function: new_node
 * Usage: Creates a new node.
 * ---------------------------
 */
struct Node *new_node(int data)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	*newNode = (struct Node){NULL,data};
	return newNode;
}

/*
 * Function: add_first
 * Usage: Adds a new node to the front of the list.
 * -------------------------------------------------
 */
void add_first(struct List *list,int data)
{
	struct Node *newNode = new_node(data);
	newNode->_next = list->_first;	
	list->_first = newNode;
	list->_size++;
}

/*
 * Function: remove_first
 * Usage: Removes the first node in the list.
 * -------------------------------------------
 */
void remove_first(struct List *list)
{
	assert(list->_first != NULL);
	struct Node *removeNode = list->_first;
	list->_first = removeNode->_next;
	free(removeNode);
	list->_size--;
}

/*
 * Function: get_first
 * Usage: Returns the value of the first node.
 * --------------------------------------------
 */
int get_first(struct List *list)
{
	//assert(list->_first != NULL);
	if (list->_first != NULL)
		return list->_first->_data;
	return 0;
}

/*
 * Function: remove_list
 * Usage: Removes the list.
 * -------------------------
 */
void remove_list(struct List *list)
{
	assert(list != NULL);
	while (list->_size)
		remove_first(list);
	free(list);
}
