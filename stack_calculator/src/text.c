#include "calculator.h"

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
	/* Kör med 1 som start, pga. vill inte ha med programmets namn. */
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
	temp[i] = '\0';
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
