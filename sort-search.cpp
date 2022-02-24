
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


//10/10 VH: Approved
This function continuously goes to the middle of the array, comparing that element to the key. 
int* binarySearch(const int key, int* a, size_t memb)
{
 int* p = a + memb / 2;
 if (p < a || p >(a + memb))
  return NULL;
 if (*p != key && memb == 0)
  return NULL;
 if (*p > key)
  return binarySearch(key, a, (memb - (memb / 2)) - 1);
 else if (*p < key)
  return binarySearch(key, p, (memb - (memb / 2)) - 1);
 if (*p == key)
  return p;
}


//10/10 VH: Approved
This function sorts integer arrays by inserting an element and shifting the other ones accordingly.

void insertionSort(int *a, size_t elements) // sorts int array
{
 int start, i;
 for (i = 1; i < elements; i++)
 {
  start = i - 1;
  int num = a[i];
  for (; start >= 0 && a[start] > num; start--)
  {
   a[start + 1] = a[start];//shifts everything over 1 spot
  }
  a[start + 1] = num;
 }
}

int main(void)
{
 int a[] = { 1, 1, 2, 2, 2, 3, 4, 5, 6, 7,};
 int* p = binarySearch(5, a, 10);
 printf("%d", (p - a) + 1);
 system("pause");
}
