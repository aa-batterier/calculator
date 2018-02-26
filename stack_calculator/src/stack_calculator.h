#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
