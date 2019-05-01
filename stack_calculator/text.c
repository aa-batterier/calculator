/*
 * Information about sourcedevelopment.
 * -------------------------------------
 *  Initial creator: Andreas Johansson.
 *  Date created: 21-04-2018
 *  Last updated by: Andreas Johansson.
 *  Date for update: 21-04-2018
 */

/*
 * File: text.c 
 * --------------
 *  Containes the functions which handles and
 *  controlls the text in this program.
 */

#include "calculator.h"

/*
 * Function: combine_arg
 * Usage: Combines all the arguments.
 * -----------------------------------
 */
char *combine_arg(int argc,char **argv)
{
	int stringSize = 1;
	char *string = (char*)malloc(stringSize);
	string[stringSize] = '\0';
	/* Start with 1 because I don't want the name of the program
	 * in the combined agrument string. */
	for (int i = 1; i < argc; i++)
	{
		int argLen = strlen(argv[i]);
		stringSize += argLen+1;
		string = (char*)realloc(string,stringSize);
		strcat(string,argv[i]);
		string[stringSize] = '\0';
	}
	return string;
}

/*
 * Function: remove_white
 * Usage: Removes all the whitespaces.
 * ------------------------------------
 */
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
	temp[i] = '\0';
	i = 0;
	for (; temp[i] != '\0'; i++)
		string[i] = temp[i];
	string[i] = '\0';
	string = (char*)realloc(string,i);
}

/*
 * Function: remove_arg_string
 * Usage: Removes the combined arguments.
 * ---------------------------------------
 */
void remove_arg_string(char *string)
{
	assert(string != NULL);
	free(string);
}

/*
 * Function: read_line
 * Usage: Reads a line from stdin.
 * --------------------------------
 */
int read_line(char *string,int len)
{
	if (fgets(string,len,stdin) == NULL)
		return 0;
	if (!remove_nl(string))
		skip_line();
	return 1;
}

/*
 * Function: remove_nl
 * Usage: Removes new line.
 * -------------------------
 */
int remove_nl(char *string)
{
	int end = strlen(string)-1;
	if (string[end] == '\n')
	{
		string[end] = '\0';
		return 1;
	}
	return 0;
}

/*
 * Function: skip_line
 * Usage: Skips a line.
 * ---------------------
 */
void skip_line(void)
{
	int c;
	while ((c = getchar()) != '\0' && c != EOF);
}
