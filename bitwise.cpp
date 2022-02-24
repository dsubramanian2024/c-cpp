//XOR Encryption:

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
#define KEY '&'
int main(void)
{
 FILE *fp = NULL;
 fopen_s(&fp, "Testile_IO.txt", "r");
 if (fp == NULL)
  exit(EXIT_FAILURE);
 FILE *fp2 = NULL;
 fopen_s(&fp, "tfile.txt", "w");
 if (fp == NULL)
  exit(EXIT_FAILURE);
 int orig_char, new_char;
 while ((orig_char = fgetc(fp)) != EOF)
 {
  new_char = orig_char ^ KEY;
  if (isprint(orig_char) && isprint(new_char))
   putc(new_char, fp2);
  else
   putc(orig_char, fp2);
 }
 fclose(fp);
 fclose(fp2);
 return 0;
}


//Bitwise Operations

int addition(int n, int m)// takes in two binary numbers
// adding two binary numbers
{
 if (n == 0)
  return m;
 return addition((n & m) << 1, n ^ m);
}
int subtraction(int n, int m)
{
 m = ~m + 1; //making m negative using 2's complement
 return addition(n, m);
}
int multiplication(int n, int m)
{
 if (m == 1)
  return n;
 if (m & 1 == 1)  // it is odd
 {
  	addition(multiplication(n, m - 1), n);
 }
 else
 {
  n = n << 1;
  	m = m >> 1;
 	 multiplication(n, m);
 }
}

int division(int n, int m)
{
 if (m > n)
  return 0;
 int j, ct, quotient = 0;
 while (n >= m)
 {
  j = m;
  ct = 1;
  while (n > (j << 1))
  {
   j = j << 1;
   ct = ct << 1;
  }
  n = subtraction(n, j);
  quotient = addition(quotient, ct);
 }
 return quotient;
}

int main(void)
{
 int x = division(13, 7);
 printf("%d\n", x);
 system("pause");
}

