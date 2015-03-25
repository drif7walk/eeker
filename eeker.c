#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int isPunctuation(char a)
{
	char* p = "!.?";

	for (int i = 0; i < 3; i++)
	{
		if (a == p[i]) return 1;
	}

	return 0;
}

int main(int argc, char** args)
{

if (argc == 1)
	srand((int)(time(NULL) / 100));
else
   srand(atoi(args[1]));

FILE *f = fopen("/home/GH0ST/literary.txt", "rb");
fseek(f, 0, SEEK_END);
long fsize = ftell(f);
fseek(f, 0, SEEK_SET);

char* string = malloc(fsize + 1);
fread(string, fsize, 1, f);
fclose(f);

int randint = rand() % fsize;
int start;

for (long i = randint; i < fsize; i++)
{
	if (string[i] == '.')
	{
		start = i + 1;
		break;
	}
}

for (long i = start; i < fsize; i++)
{
	printf("%c",string[i]);
	
	if (isPunctuation(string[i])) break;
}

printf("\r\n");
return 0;

}
