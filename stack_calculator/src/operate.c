#include "calculator.h"

int high_priority(const char operator,char *listOperator)
{
	if (listOperator == NULL)
	{
		return 0;
	}
	return (operator == '+' || operator == '-') && (*listOperator == '*' || *listOperator == '/') ? 1 : 0;
}

double calculate(const char operator,const double first,const double second)
{
	switch (operator)
	{
		case '+':
			return first + second;
		case '-':
			return first - second;
		case '*':
			return first * second;
		case '/':
			return second / first; // Need to change because the one you divide with comes first out from the stack.
	}
	return -7999;
}

char *combined_string(char **strings,int number)
{
	char *newString = (char*)malloc(1);
	newString[0] = '\0';
	for (int i = 1; i < number; i++)
	{
		newString = realloc(newString,strlen(newString)+strlen(strings[i])+1);
		strcat(newString,strings[i]);
		newString[strlen(newString)] = '\0';
	}
	return newString;
}

int is_number_or_operator(char value)
{
	if (value == '+' || value == '-' || value == '*' || value == '/')
	{
		return 0;
	}
	else if (isdigit(value))
	{
		return 1;
	}
	return -1;
}
