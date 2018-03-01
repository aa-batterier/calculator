#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node
{
	struct Node *next;
	void *value;
};

struct List
{
	struct Node *first;
	int size;
};

/* list.c */

struct List *new_list(void);
struct Node *new_node(void *value);
void add_first(struct List *list,void *value);
void remove_first(struct List *list);
void remove_list(struct List *list);
void *new_value(void *value);
void *get_first(struct List *list);

/* operator.c */
int high_priority(const char operator,char *listOperator);
double calculate(const char operator,const double first,const double second);
char *combined_string(char **strings,int number);
int is_number_or_operator(char value);
