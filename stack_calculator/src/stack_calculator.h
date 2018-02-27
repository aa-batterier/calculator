#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node
{
	struct Node *next;
	void *data;
};

struct List
{
	struct Node *first;
	int size;
};

struct List *new_list(void);
struct Node *new_node(void *data);
void add_first(struct List *list,void *data);
void remove_first(struct List *list);
void *get_first(struct List *list);
void remove_list(struct List *list);
