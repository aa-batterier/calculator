/*
 * Information about sourcedevelopment.
 * -------------------------------------
 *  Initial creator: Andreas Johansson.
 *  Date created: 21-04-2018
 *  Last updated by: Andreas Johansson.
 *  Date for update: 21-04-2018
 */

/*
 * File: main.c 
 * --------------
 *  Contians the main function for this program.
 */

#include "calculator.h" 

/*
 * Function: main
 * Usage: It's the main function.
 * ------------------------------
 */
int main(int argc,char **argv)
{
	if (argc <= 1)
	{
		fprintf(stderr,"usage: %s <calculation... or %s terminal\n",argv[0],argv[0]);
		exit(1);
	}
	struct List *numberList = new_list(),*operatorList = new_list();
	char *string = combine_arg(argc,argv);
	// Säkerhets risk med för stort argument.
	if (strlen(string) > MAX)
	{
		fprintf(stderr,"Too big argument!\n");
		exit(1);
	}
	if (strncmp("terminal",string,8) == 0)
	{
		/* Tar fram en ternimal och hantera beräkningarna i terminalen istället för i argumenten till programmet,
		 * pga. det är svårt att få agrummenten att hantera * fritt och paranterser.*/
		for (;;)
		{
			char *loopString = (char*)malloc(MAX);
			printf("?> ");
			if (!read_line(loopString,MAX))
				goto end;
			remove_white(loopString);
			loopString = (char*)realloc(loopString,strlen(loopString)+1);
			if (!split_string(loopString,numberList,operatorList))
			{
				fprintf(stderr,"split_string failed\n");
				exit(1);
			}
			free(loopString);
			combined_calculate(numberList,operatorList);
			printf("!> = %g\n",get_first(numberList));
			clean_list(numberList);
			clean_list(operatorList);
		}
	}
	if (!split_string(string,numberList,operatorList))
	{
		fprintf(stderr,"split_string failed\n");
		exit(1);
	}
	combined_calculate(numberList,operatorList);
	printf(" = %g\n",get_first(numberList));
end:
	remove_arg_string(string);
	remove_list(numberList);
	remove_list(operatorList);
	exit(0);
}
