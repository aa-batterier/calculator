#include "stack_calculator.h"

int main(int argc,char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr,"usage: %s <equations...\n",argv[0]);
		exit(1);
	}
	struct List *numberList = new_list(),*operationList = new_list();

	/* Skapar en stor sträng av alla argument. */
	char *argString = (char*)malloc(1);
	*argString = '\0';
	for (int i = 1; i < argc; i++)
	{
		argString = (char*)realloc(argString,strlen(argString)+strlen(argv[i])+1);
		strcat(argString,argv[i]);
		argString[strlen(argString)] = '\0';
	}

	/* Lägg in argString i köerna. */
	int i = 0;
	for (; argString[i] != '\0'; i++)
	{
		if (argString[i] == '*' || argString[i] == '/' || argString[i] == '+' || argString[i] == '-')
		{
			// Högre prioritet.
			if (get_first(operationList) != NULL)
			{
				if ((argString[i] == '+' || argString[i] == '-') && (*(char*)get_first(operationList) == '*' || *(char*)get_first(operationList) == '/'))
				{
					double firstNumber = *(double*)get_first(numberList),combinedNumber;
					remove_first(numberList);
					double secondNumber = *(double*)get_first(numberList);
					remove_first(numberList);
					if (*(char*)get_first(operationList) == '+')
					{
						combinedNumber = firstNumber + secondNumber;
					}
					else if (*(char*)get_first(operationList) == '-')
					{
						combinedNumber = firstNumber - secondNumber;
					}
					add_first(numberList,&combinedNumber);
					remove_first(operationList);
				}
			}
			add_first(operationList,&argString[i]);
		}
		else if (isdigit(argString[i]))
		{
			double number = argString[i]-'0';
			add_first(numberList,&number);
		}
	}
		if (argString[i] == '\0')
		{
			while (operationList->size > 0)
			{
				double firstNumber = *(double*)get_first(numberList),combinedNumber;
				remove_first(numberList);
				double secondNumber = *(double*)get_first(numberList);
				remove_first(numberList);
				if (*(char*)get_first(operationList) == '*')
				{
					combinedNumber = firstNumber * secondNumber;
					add_first(numberList,&combinedNumber);
				}
				else if (*(char*)get_first(operationList) == '/')
				{
					combinedNumber = firstNumber / secondNumber;
					add_first(numberList,&combinedNumber);
				}
				else if (*(char*)get_first(operationList) == '+')
				{
					combinedNumber = firstNumber + secondNumber;
					add_first(numberList,&combinedNumber);
				}
				else if (*(char*)get_first(operationList) == '-')
				{
					combinedNumber = firstNumber - secondNumber;
					add_first(numberList,&combinedNumber);
				}
				remove_first(operationList);
			}
		}
	printf("%lf\n",*(double*)get_first(numberList));
	remove_list(numberList);
	remove_list(operationList);
	free(argString);
	exit(0);
}