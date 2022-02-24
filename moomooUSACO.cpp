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


int fmoomoo(const char *file)
// File I/O Packet Exercise 6 (where the input and ouput is the same file)
{
	//Farmer John loves momomommmmooooooooooocow, but all the cows do momommmooomooooooo.
	FILE *fp = NULL;
	//fopen_s(&fp, file, "r");
	fp = fopen(file, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	int sensize = getFsize(file);
	char *sen;
	sen = (char *)(malloc((sensize + 1) * sizeof(char)));
	fgets(sen, sensize, fp);
	sen[sensize] = '\0';
	const char word[] = "moo";
	size_t wdsize = strlen(word);
	char *sen2;
	sen2 = (char *)(malloc(sensize * sizeof(char)));
	char *p = strstr(sen, word);
	if (*p != NULL)
	{
		size_t n = p - sen;
		memcpy(sen2, sen, n);
		p += wdsize;
		char *q;
		q = &sen2[n];
		while (*p != NULL && p >= sen && p <= (sen + sensize)) // make sure p does not go out of the memory that belongs to me
		{
			*q = *p;
			if (memcmp(word, q - (wdsize - 1), wdsize) == 0)
				q = q - (wdsize - 1);
			else
				q++;
			p++;
		}
		*q = NULL;
	}
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


int fmoomoo2(void)
// File I/O Packet Exercise 6 for USACO
{
	FILE *fp = NULL;
	//fopen_s(&fp, "censor.in", "r");
	fp = fopen("censor.in", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	char *sen;
	sen = (char *)(malloc((1000005) * sizeof(char)));
	fgets(sen, 1000005, fp);
	size_t sensize = strlen(sen) - 1;
	sen[sensize] = '\0';
	char *word; // read it from the second line
	word = (char *)(malloc((105) * sizeof(char)));
	fgets(word, 101, fp);
	size_t wdsize = strlen(word);
	if (word[wdsize - 1] == '\n')
	{
		wdsize--;
		word[wdsize] = '\0';
	}
	char *sen2;
	sen2 = (char *)(malloc((sensize + 1) * sizeof(char)));
	char *p = strstr(sen, word);
	if (p != '\0')
	{
		size_t n = p - sen;
		memcpy(sen2, sen, n);
		p += wdsize;
		char *q;
		q = &sen2[n];
		while (p != '\0' && p >= sen && p <= (sen + sensize))
		{
			*q = *p;
			if (memcmp(word, q - (wdsize - 1), wdsize) == 0)
				q = q - (wdsize - 1);
			else
				q++;
			p++;
		}
		q = '\0';
	}
	else
		sen2 = sen;
	fclose(fp);
	FILE *fp2 = NULL;
	//fopen_s(&fp2, "censor.out", "w");
	fp2 = fopen("censor.out", "w");
	if (fp2 == NULL)
		exit(EXIT_FAILURE);
	fprintf(fp2, "%s", sen2);
	fclose(fp2);
	return 0;
}

int main(void)
{
	fmoomoo2();
	//system("pause");
}

