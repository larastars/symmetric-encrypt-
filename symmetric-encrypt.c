
#include <stdio.h>
#include <stdlib.h>

char symmetric_encrypt(char a);
int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("error! Enter 3 arguments\n");
	}
	char String;
	int key = atoi(argv[1]);
	srandom(key);
	FILE *infile = NULL;
	infile = fopen(argv[2], "r");
	//open file in read mode and make sure it opens correctly 
	if (infile == NULL)
	{
		printf("Error in opening the file\n");
		exit(1);
	}
	//write to a file
	FILE *outfile = NULL;
	outfile = fopen(argv[3], "w");
	//check to make sure it opens correctly
	if (outfile == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}
	//read each character from infile and pass it to symmetric_encrypt
	while (fscanf(infile, "%c", &String) != EOF)
	{
		//pass in a character to the function which returns
		//encrypted character 
		char a = symmetric_encrypt(String);
		fprintf(outfile, "%c",a);
	}
	//close files
	fclose(infile);
	fclose(outfile);
	exit(0);
	return 0;
}

char symmetric_encrypt(char p)
{
	int r = random()%97;
	int p1;
	int c1;
	char c;
	
	if (p == '\t')
	{
		p1 = 0;
	}
	else if (p == '\n')
	{
		p1 = 1;
	}
	else 
	{
		p1 =((int)p) -30;
	}
	c1 = p1^r;
	if (c1 == 0)
	{
		c = '\t';
	}
	else if (c1 == 1)
	{
		c = '\n';
	}
	else
	{
		c =(char) ((int)c1) + 30; 
	}
	return c;
}
	
