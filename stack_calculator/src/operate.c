/*
 * Information about sourcedevelopment.
 * -------------------------------------
 *  Initial creator: Andreas Johansson.
 *  Date created: 21-04-2018
 *  Last updated by: Andreas Johansson.
 *  Date for update: 21-04-2018
 */

/*
 * File: operate.c 
 * --------------
 *  Provides the functions which do all the calculations
 *  and comparison in the program. This is the engine of
 *  the program.
 */

#include "calculator.h"

/*
 * Function: split_string
 * Usage: Splits the string.
 * --------------------------
 */
int split_string(char *string,struct List *numberList,struct List *operatorList)
{
	for (char *p = string; *p != '\0';)
	{
		/* Merges the numbers into one. */
		if (isdigit(*p))
		{
			int numberSize = 0;
			for (; isdigit(*p); numberSize++,p++);
			add_first(numberList,to_number(p-numberSize,p));
		}
		/* If it is an operator. */
		else if (is_operator(*p))
		{
			if (operator_value(*p) < operator_value(get_first(operatorList)))
				add_first(numberList,calculate(numberList,operatorList));
			add_first(operatorList,*p);
			p++;
		}
		else
		{
			fprintf(stderr,"Doesn't recognize the \'%c\' operator!\n",*p);
			return 0;
		}
	}
	return 1;
}

/*
 * Function: to_number
 * Usage: Turns a string into an integer.
 * ---------------------------------------
 */
int to_number(char *begin,char *end)
{
	//int sum = 0,i = pow(10,end-begin);
	int sum = 0,i = pow(10,end-begin-1);
	//for (char *p = begin; p <= end; i /= 10,p++)
	for (char *p = begin; p < end; i /= 10,p++)
		sum += (*p-'0')*i;
	return sum;
}

/*
 * Function: is_operator
 * Usage: Checks if the char is an vaild operator.
 * ------------------------------------------------
 */
int is_operator(const int op)
{
	int operators[] = {'+','-','*','/'};
	/* Borde implementera binär sökning här. */
	for (int i = 0; i < 4; i++)
		if (operators[i] == op)
			return 1;
	return 0;
}

/*
 * Function: operator_value
 * Usage: Returns the value of the operator.
 * ------------------------------------------
 */
int operator_value(const int operator)
{
	if (operator == '+' || operator == '-' || operator == 0)
		return 0;
	return 1;
}

/*
 * Function: calculate
 * Usage: Calculates a value.
 * ---------------------------
 */
int calculate(struct List *numberList,struct List *operatorList)
{
	int first = get_first(numberList); //Sist in, först ut.
	remove_first(numberList);
	int second = get_first(numberList); //Först in, sist ut.
	remove_first(numberList);
	int operator = get_first(operatorList);
	remove_first(operatorList);
	switch(operator)
	{
		case '+':
			return first + second;
		case '-':
			return second - first;
		case '*':
			return first * second;
		case '/':
			if (first == 0)
			{
				fprintf(stderr,"Can't divide by zero!");
				exit(1);
			}
			return second / first;
		default:
			fprintf(stderr,"No opeator match.\n");
			exit(1);
	}
	return 0;
}

/*
 * Function: combined_calculate
 * Usage: Calculate everything.
 * ------------------------------
 */
void combined_calculate(struct List *numberList,struct List *operatorList)
{
	while (numberList->_size && operatorList->_size)
		add_first(numberList,calculate(numberList,operatorList));
}
