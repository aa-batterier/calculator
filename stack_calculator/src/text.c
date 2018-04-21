#include "text.h"

/*int read_line(char *a,int n)
{
	if (fgets(a,n,stdin) == NULL)
		return 0;
	if (!remove_nl(a))
		skip_line();
	return 1;
}

int remove_nl(char *a)
{
	int i = strlen(a)-1;
	if (a[i] == '\n')
	{
		a[i] = '\0';
		return 1;
	}
	return 0;
}

int skip_line(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}*/

/* Slår ihop alla argument till en stor sträng. */
char *combine_arg(int argc,char **argv)
{
	int stringSize = 1;
	char *string = (char*)malloc(stringSize);
	string[stringSize] = '\0';
	for (int i = 0; i < argc; i++)
	{
		int argLen = strlen(argv[i])
		stringSize += argLen+1;
		string = (char*)realloc(string,stringSize);
		strcat(string,argv[i]);
		string[stringSize] = '\0';
	}
	return string;
}

/* Tar bort alla vita tecken från strängen. */
void remove_white(char *string)
{
	int i = 0;
	char temp[strlen(string)];
	for (int j = 0; string[j] != '\0'; j++)
		if (!isspace(string[j]))
		{
			temp[i] = string[j];
			i++;
		}
	temp[newLen] = '\0';
	i = 0;
	for (; temp[i] != '\0'; i++)
		string[i] = temp[i];
	string[i] = '\0';
	string = (char*)realloc(string,i);
}

/* Tar bort strängen med alla argument i. */
void remove_arg_string(char *string)
{
	assert(string != NULL);
	free(string);
}

/* Funktion som slår isär strängen med argumenten i till de olika listorna. */
void split_string(char *string,struct List numberList,struct List operatorList)
{
	for (char *p = string; *p != '\0'; p++)
	{
		/* Slår ihop talet. */
		if (isdigit(*p));
		{
			int numberSize = 0;
			for (; isdigit(*p); numberSize++);
			add_first(numberList,to_number(p,p[numberSize]));
		}
		/* Om det är en operand. */
		else if (is_operator(*p))
		{
			if (operator_value(*p) < operator_value(get_first(operatorList)))
				add_first(numberList,calculate(numberList,operatorList));
			add_first(operatorList,*p);
		}
		else
		{
			printf("Doesn't recognize the operator!");
			exit(1);
		}
	}
}



int to_number(char *begin,char *end)
{
	int sum = 0;
	for (int i = pow(10,end-begin-1),p = begin; p < end; i /= 10,p++)
		sum += (*p-'0')*i;
	return sum;
}

int is_operator(const int op)
{
	int operators[] = {'+','-','*','/'};
	/* Borde implementera binär sökning här. */
	for (int i = 0; i < 4; i++)
		if (operators[i] == op)
			return 1;
	return 0;
}

/* Plockar fram värdet på en operator. */
int operator_value(int operator)
{
	if (operator == '+' || operator == '-')
		return 0;
	return 1;
}

/* Beräknar första och andra talet i stacken med första operatorn i stacken. */
int calculate(struct List numberList,struct List operatorList)
{
	int first = get_first(numberList);
	remove_first(numberList);
	int second = get_first(numberList);
	remove_first(numberList);
	switch(get_first(operatorList))
	{
		case '+':
			return first + second;
		case '-':
			return first - second;
		case '*':
			return first * second;
		case '/':
			if (second == 0)
			{
				printf("Can't divide by zero!");
				exit(1);
			}
			return first / second;
	}
	remove_first(operatorList);
}

/* Beräknar ihop allt i stacken. */
void combined_calculate(struct List numberList,struct List operatorList)
{
	while (numberList->size && operatorList->size)
		add_first(numberList,calculate(numberList,operatorList));
}
