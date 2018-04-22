#include "calculator.h" 

int main(int argc,char **argv)
{
	if (argc <= 1)
	{
		fprintf(stderr,"usage: %s <calculation...\n",argv[0]);
		exit(1);
	}
	struct List *numberList = new_list(),*operatorList = new_list();
	char *string = combine_arg(argc,argv);
	if (!split_string(string,numberList,operatorList))
	{
		fprintf(stderr,"split_string failed\n");
		exit(1);
	}
	remove_arg_string(string);
	combined_calculate(numberList,operatorList);
	printf(" = %d\n",get_first(numberList));
	remove_list(numberList);
	remove_list(operatorList);
	exit(0);
}
