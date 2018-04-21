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

struct List *new_list(void);
struct Node *new_node(void *data);
void add_first(struct List *list,void *data);
void remove_first(struct List *list);
void *get_first(struct List *list);
void remove_list(struct List *list);
