#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

struct List
{
	struct Node *_first;
	int _size;
};

struct Node
{
	struct Node *_next;
	//void *_data;
	/* Har bytt till int pga. lättare att hantera operator tecknen också. */
	int _data;
};

/* list.c */
struct List *new_list(void);
struct Node *new_node(int data);
void add_first(struct List *list,int data);
void remove_first(struct List *list);
int get_first(struct List *list);
void remove_list(struct List *list);

/* text.c */
char *combine_arg(int argc,char **argv);
void remove_white(char *string);
void remove_arg_string(char *string);

/* operator.c */
int split_string(char *string,struct List *numberList,struct List *operatorList);
int to_number(char *begin,char *end);
int is_operator(const int op);
int operator_value(const int operator);
int calculate(struct List *numberList,struct List *operatorList);
void combined_calculate(struct List *numberList,struct List *operatorList);
