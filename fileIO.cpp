# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>
# include <stdbool.h>
# include <time.h>
# include <string.h>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma warning(disable:4996)
/*
Chapter 22 Exercise 2
(a) "wb+"
(b) "ab"
(c) "r"
(d) "rb"

Chapter 22 Exercise 10
change: putc(ch, dest_fp);
to: if( putc(ch, dest_fp) == EOF)
		exit (EXIT_FAILURE);
*/

long getFsize(const char * filename)
//File I/O Packet Exercise 1
{
	FILE *fp = NULL;
	//fopen_s(&fp, filename, "r");
	fp = fopen(filename, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	fseek(fp, 0L, SEEK_END);
	long bytenum = ftell(fp);
	fclose(fp);
	return bytenum;
}

int size(void)
{
	// File I/O Packet Exercise 2
	FILE *fp1 = NULL;
	//fopen_s(&fp1, "./tfile.txt", "w"); //tfile is the name of the text file
	fp1 = fopen("./tfile.txt", "w");
	if (fp1 == NULL)
		exit(EXIT_FAILURE);
	fprintf(fp1, "5000000, 6000000, 7000000, 8000000");
	fclose(fp1);

	FILE *fp2 = NULL;
	//fopen_s(&fp2, "./bfile.txt", "wb"); //bfile is the name of the binary file
	fp2 = fopen("./bfile.txt", "wb");
	if (fp2 == NULL)
		exit(EXIT_FAILURE);
	fprintf(fp2, "5000000, 6000000, 7000000, 8000000");
	fclose(fp2);

	printf("%d\n", getFsize("./tfile.txt"));
	printf("%d", getFsize("./bfile.txt"));
	fclose(fp1);
	fclose(fp2);
	return 0;
}


int randArray(const char *file, const char *output)
// File I/O Packet Exercise 3
{
	FILE *fp = NULL;
	//fopen_s(&fp, file, "r");
	fp = fopen(file, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	int x;
	int y;
	//fscanf_s(fp,"%d,%d", &x, &y);
	fscanf(fp, "%d,%d", &x, &y);
	srand(time(0));
	FILE *out = NULL;
	//fopen_s(&out, output, "w");
	out = fopen(output, "w");
	for (int i = 0; i < x; i++)
	{
		for (int z = 0; z < y; z++)
			fprintf(out, "%3d", (rand() % (9 + 1 - 0) + 0));
		fprintf(out, "\n");
	}
	fclose(fp);
	return 0;
}

int substr(const char *file, int num)
// File I/O Packet Exercise 4
{
	FILE *fp = NULL;
	//fopen_s(&fp, file, "r");
	fp = fopen(file, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	int commact = 0;
	char ch;
	while (commact != num - 1)
	{
		ch = fgetc(fp);
		if (ch == ',')
			commact++;
	}
	while ((ch = fgetc(fp)) != ',')
		printf("%c", ch);
	fclose(fp);
	return 0;
}


int freplace(const char *file, const char *oldstr, const char *newstr)
// File I/O Packet Exercise 5
{
	FILE *fp = NULL;
	//fopen_s(&fp, file, "r");
	fp = fopen(file, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	int sensize = getFsize(file);
	char *sen;
	sen = (char *)(malloc((sensize + 1) * sizeof(char)));
	fgets(sen, sensize, fp);
	size_t oldsize = strlen(oldstr);
	size_t newsize = strlen(newstr);
	char *p = strstr(sen, oldstr);
	char *p2;
	p2 = sen;
	char *sen2;
	sen2 = (char *)(malloc(40 * sizeof(char)));
	char *q;
	q = sen2;
	while (p != NULL)
	{
		memcpy(q, p2, p - p2);
		q += p - p2;
		memcpy(q, newstr, newsize);
		q += newsize;
		p2 = p + oldsize;
		p = strstr(p2, oldstr);
	}
	p = sen + sensize + 1;
	memcpy(q, p2, p - p2);// copies the rest of the sentence into sen2

	fclose(fp);
	FILE *fp2 = NULL;
	//fopen_s(&fp2, file, "w");
	fp2 = fopen(file, "w");
	if (fp2 == NULL)
		exit(EXIT_FAILURE);
	fprintf(fp2, "%s", sen2);
	fclose(fp);
	return 0;
}
