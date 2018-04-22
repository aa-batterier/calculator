#include "calculate.h"

/* Funktion som slår isär strängen med argumenten i till de olika listorna. */
int split_string(char *string,struct List *numberList,struct List *operatorList)
{
	for (char *p = string; *p != '\0'; p++)
	{
		/* Slår ihop talet. */
		if (isdigit(*p));
		{
			int numberSize = 0;
			for (; isdigit(*p); numberSize++);
			add_first(numberList,to_number(p,p[numberSize]));
			p += numberSize;
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
			fprintf(stderr,"Doesn't recognize the \'%c\' operator!",*p);
			return 0;
		}
	}
	return 1;
}

/* Gör om en sträng till ett heltal. */
int to_number(char *begin,char *end)
{
	int sum = 0;
	for (int i = pow(10,end-begin-1),p = begin; p < end; i /= 10,p++)
		sum += (*p-'0')*i;
	return sum;
}

/* Kollar teckent verkligen är en operator. */
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
int operator_value(const int operator)
{
	if (operator == '+' || operator == '-')
		return 0;
	return 1;
}

/* Beräknar första och andra talet i stacken med första operatorn i stacken. */
int calculate(struct List *numberList,struct List *operatorList)
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
				fprintf(stderr,"Can't divide by zero!");
				/* Borde inte göra exit() här, men jag vet inte riktigt hur jag ska göra
				 * error hantering bra ifrån denna funktionen, pga. 0 och -1 kan vara riktiga
				 * värden som inte behöver betyda fel. */
				exit(1);
			}
			return first / second;
	}
	remove_first(operatorList);
}

/* Beräknar ihop allt i stacken. */
void combined_calculate(struct List *numberList,struct List *operatorList)
{
	while (numberList->size && operatorList->size)
		add_first(numberList,calculate(numberList,operatorList));
}
