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
// don't have to use _s

int baseExp(int base, int exp)
// Recursion Packet Exercise 1
{
 if (exp == 1)
  return base;
  if (exp == 0)
  return 1;
 return base * baseExp(base, exp - 1);
}

int prtn20(int n)
// Recursion Packet Exercise 2
{
 if (n < 0)
  return 0;
 printf("%d ", n);
 prtn20(n - 1);
}

int prt02n(int n)
// Recursion Packet Exercise 3
{
 if (n < 0)
  return 0;
 prt02n(n - 1);
 printf("%d ", n);
}

int countsdigits(int n)
// Recursion Packet Exercise 4
{
 if (n < 1)
  return 0;
 return (countsdigits(n/10)) + 1;
}


char* reverse(const char *str)
// Recursion Packet Exercise 5
{
 static char *newstr = (char*)malloc(1000);
 static int n = 0;
 if (n == 0)
  newstr += 998;
 if (*str == '\0')
 {
  newstr += (n + 1);
  *newstr = '\0';
  newstr -= (n);
  return newstr;
 }
 n++;
 *newstr = *str;
 newstr--;
 return reverse(str + 1);
}
int sum(int n)
// Recursion Packet Exercise 6
{
 if (n < 0)
  return 0;
 return sum(n - 1) + n;
}
int findmin(int a[], int n)
// Recursion Packet Exercise 7 inc
{
 if (n < 0)
  return 0;
 //if (findmin(a[], n - 1) < a[n - 1])
  //return findmin(a[], n - 1);
}
int findsum(int a[], int n)
// Recursion Packet Exercise 8
{
 if (n < 1)
  return 0;
 return findsum(a, n - 1) + a[n - 1];
}
int ispalendrome(char a[], int n)
// Recursion Packet Exercise 9
{
 if (a[n - 1] != *a)
  return 0;
 if (&a[n - 1] == a)
  return 1;
 return ispalendrome(a + 1, n - 2);
}
void drawtriangle(int n)
// Recursion Packet Exercise 10
{
 if (n < 0)
  return;
 drawtriangle(n - 1);
 for (int i = 1; i <= n; i++)
 {
  printf("#");
 }
 printf("\n");
}
void drawtriangleupsidedown(int n)
// Recursion Packet Exercise 11
{
 if (n < 0)
  return;
 for (int i = 1; i <= n; i++)
 {
  printf("#");
 }
 printf("\n");
 drawtriangleupsidedown(n - 1);
}
int GCD(int n, int m)
// Recursion Packet Exercise 12
{
 if (n == 0)
  return m;
 if (m == 0)
  return n;
 return GCD(m, n % m);
}


void binint(int n)
// Recursion Packet Exercise 13 part 1
{
 static int ct = 0;
 static int ct2 = 0;
 if (n == 0)
  return;
 ct++;
 binint((n - (n % 2)) / 2);
 ct2++;
 printf("%d", n % 2);
 if ((ct - ct2) % 4 == 0)
  printf(" ");
}
void hexint(int n)
// Recursion Packet Exercise 13 part 2
{
 static int ct = 0;
 static int ct2 = 0;
 if (n == 0)
  return;
 ct++;
 hexint((n - (n % 16)) / 16);
 ct2++;
 printf("%d", n % 16);// change this into the hex digits 0123...9ABCDEF
 if ((ct - ct2) % 2 == 0)
  printf(" ");
}
int f(int x, int y)
// Recusrion Packet Exercise 14
{
 if (x <= 0)
  return x - y;
 else if (x % 2 == 0)
  return x - f(x - 2, y - 1);
 else if (x % 2 == 1)
  return y - f(y - 2, x - 1);
}


char* nested(char *str)
{
	while (str != NULL && *str != '\0' && *str != '(' && *str != '{' && *str != ')' && *str != '}') //basecases
	{
		str += 1;
	}
	if (str == NULL || *str == '\0')
	{
		return NULL;
	}
	if (*str == ')' || *str == '}')
	{
		return str;
	}
	char *end;
	end = nested(str + 1);
	//make another if statement checking -1
	if (end == NULL)
	{
		return (char*)-1;
	}
	if ((*str == '(' && *end != ')') || (*str == '{' && *end != '}'))
	{
		return (char*)-1; //return a null continuously till bottom of stack and to user
	}
	return nested(end + 1);
}
/*
Advanced Struct Packet Exercises
1. 12
2. 12
3. 8

*/

int main(void)
{
	//char str[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
	/*char* hi = (char*)malloc(sizeof(char) * 6);
	strcpy(hi, str);
	printf("%c", hi[2]);
	printf("%c", str[2]);
	printf("%c", *(hi + 2));
	printf("%c", *(str + 2));*/

	char str[] = "{{}}()";
	//char x = ispalendrome(str, 7);
	//int x = f(10,5);
	//printf("%d", x);
	//printf("Enter an integer: ");
	//int n;
	//scanf("%d", &n);
	char* x;
	x = nested(str);
	if (x == NULL)
	{
		printf("GOOD! Brackets are nested!!");
	}
	else
	{
		printf("OOPS! Brackets are not nested!");
	}
	system("pause");
}


