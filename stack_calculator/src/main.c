#include "calculator.h"

int main(int argc,char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr,"usage: %s <equations....\n",argv[0]);
		exit(1);
	}
	struct List *numberList = new_list(),*operatorList = new_list();
	char *argString = combined_string(argv,argc);
	for (int i = 0; argString[i] != '\0'; i++)
	{
		int isNumberOrOperator = is_number_or_operator(argString[i]);
		if (isNumberOrOperator == 0)
		{
			char *listOperator = (char*)get_first(operatorList);
			if (high_priority(argString[i],listOperator))
			{
				double first = *(double*)get_first(numberList);
				remove_first(numberList);
				double second = *(double*)get_first(numberList);
				remove_first(numberList);
				double combinedNumber = calculate(*listOperator,first,second);
				add_first(numberList,&combinedNumber);
				remove_first(operatorList);
			}
			add_first(operatorList,&argString[i]);
		}
		else if (isNumberOrOperator == 1)
		{
			double newNumber = argString[i]-'0';
			add_first(numberList,&newNumber);
		}
		else
		{
			fprintf(stderr,"wrong input: %c\n",argString[i]);
			exit(1);
		}
	}
	free(argString);
	while (operatorList->size > 0)
	{
		char listOperator = *(char*)get_first(operatorList);
		remove_first(operatorList);
		double first = *(double*)get_first(numberList);
		remove_first(numberList);
		double second = *(double*)get_first(numberList);
		remove_first(numberList);
		double combinedNumber = calculate(listOperator,first,second);
		add_first(numberList,&combinedNumber);
	}
	printf("%g\n",*(double*)get_first(numberList));
	remove_list(numberList);
	remove_list(operatorList);
	exit(0);
}
