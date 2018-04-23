/*
 * Information about sourcedevelopment.
 * -------------------------------------
 *  Initial creator: Andreas Johansson.
 *  Date created: 21-04-2018
 *  Last updated by: Andreas Johansson.
 *  Date for update: 21-04-2018
 */

/*
 * File: calculator.h
 * --------------
 *  Provides tools for the calculator program.
 */

#ifndef _calculator_h
#define _calculator_h

/* Include files necessary for the headerfile. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

/* Typedefinitions. */

/*
 * Typedefinition: List
 * ---------------------
 *  Contains all the information the list/stack needs.
 *  _first points to the first node in the stack.
 *  _size is the numbers of nodes in the stack.
 */
struct List
{
	struct Node *_first;
	int _size;
};

/*
 * Typedefinition: Node
 * ---------------------
 *  Contains all the information the node needs.
 *  _next points to the next node in the stack.
 *  I changed the _data to an int from a void*
 *  because it's easier to handle an int, also the operators
 *  can be stored in an int. For an update I would change this
 *  to a double.
 */
struct Node
{
	struct Node *_next;
	int _data;
};

/* Function prototypes. */

/* list.c */

/*
 * Function: new_list
 * Usage: Creates a new list.
 * ---------------------------
 *  new_list creates a new list.
 *  It returns a pointer to the
 *  new list.
 */
struct List *new_list(void);

/*
 * Function: new_node
 * Usage: Creates a new node.
 * ---------------------------
 *  new_node creates a new node with
 *  the data sendt in though the parameter
 *  to the function. It returns a pointer
 *  to the new node.
 */
struct Node *new_node(int data);

/*
 * Function: add_first
 * Usage: Adds a new node to the front of the list.
 * -------------------------------------------------
 *  add_first creates and adds a new node first in the list.
 */
void add_first(struct List *list,int data);

/*
 * Function: remove_first
 * Usage: Removes the first node in the list.
 * -------------------------------------------
 *  remove_first removes the first node in the list.
 */
void remove_first(struct List *list);

/*
 * Function: get_first
 * Usage: Returns the value of the first node.
 * --------------------------------------------
 *  get_first returns the data from the first node,
 *  if there doesn't exist a first node get_first
 *  returns 0.
 */
int get_first(struct List *list);

/*
 * Function: remove_list
 * Usage: Removes the list.
 * -------------------------
 *  remove_list removes the list which is specified in the parameters.
 *  You don't need to remove all the nodes in the list first, remove_list
 *  do this for you.
 */
void remove_list(struct List *list);

/* text.c */

/*
 * Function: combine_arg
 * Usage: Combines all the arguments.
 * -----------------------------------
 *  combine_arg combines the amount of arguments(argv) specified by argc.
 *  combine_arg allocates new memory where it stores the combined arguments in
 *  and returns a pointer to the new memory. All whitespaces are removed.
 */
char *combine_arg(int argc,char **argv);

/*
 * Function: remove_white
 * Usage: Removes all the whitespaces.
 * ------------------------------------
 *  remove_white removes all the whitespaces in the string
 *  specified in the parameters.
 */
void remove_white(char *string);

/*
 * Function: remove_arg_string
 * Usage: Removes the combined arguments.
 * ---------------------------------------
 *  remove_arg_string frees the memory which holds the string
 *  containing the combined arguments.
 */
void remove_arg_string(char *string);

/* operate.c */

/*
 * Function: split_string
 * Usage: Splits the string.
 * --------------------------
 *  split_string splits the string char by char into the two stacks.
 *  It does allso calculate if an operator who is put in has lower ranking then the one already
 *  in the stack. split_string while return 1 on success and 0 on failure.
 */
int split_string(char *string,struct List *numberList,struct List *operatorList);

/*
 * Function: to_number
 * Usage: Turns a string into an integer.
 * ---------------------------------------
 *  to_number turns a string which start at begin and ends before end into an integer which it
 *  then returns.
 */
int to_number(char *begin,char *end);

/*
 * Function: is_operator
 * Usage: Checks if the char is an vaild operator.
 * ------------------------------------------------
 *  is_operator checks if the char(I use an int(explained in Node)) is one of the
 *  four vaild operators: +, -, *, and /. is_operator returns 1 on success and 0 on failure.
 */
int is_operator(const int op);

/*
 * Function: operator_value
 * Usage: Returns the value of the operator.
 * ------------------------------------------
 *  operator_value returns the value of the operator specified in the parameters.
 *  The more important operators has heigher value.
 */
int operator_value(const int operator);

/*
 * Function: calculate
 * Usage: Calculates a value.
 * ---------------------------
 *  calculate calculates a value from the first and second nodes in the number list/stack with the first operator from
 *  the operator list. It returns the value calculated.
 *  Because 0 and -1 is vailed returns, I have choosen to run exit() when trying
 *  to divid by zero.
 */
int calculate(struct List *numberList,struct List *operatorList);

/*
 * Function: combined_calculate
 * Usage: Calculate everything.
 * ------------------------------
 *  combined_calculate calculate until either number list/stack or operator list/stack is empty.
 *  It utilize the calculate function in a loop.
 */
void combined_calculate(struct List *numberList,struct List *operatorList);

#endif
