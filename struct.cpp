
# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>

# include <math.h>
# include <stdbool.h>
# include <time.h>
# include <string.h>
struct Color { int r; int g; int b; } test;
struct Box {
 Color  c;    	
 int base;    	
 int height;    	
 int depth;
} test;
Box Test = { 50, 3, 5, {255, 255, 0} };
/*
 Exercises in Online Struct Packet
1) The name of A's struct is Point while Point is the name of the variable of the struct in B
2) it is not supposed to be POINT a. the point should be replaced with the name of the struct
3) What is wrong with the following code?   Fix it.
struct { double x; double y; } POINT; const POINT a; test.x = .25; test.y = .75;
3) can't be test bc test is not the variable. I think it would be a.x = .25; a.y = .75
*/
struct POINT{ double x; double y; }  a;
float ptdist(POINT p1, POINT p2)
// Struct Packet Exercise 4
{
 int xdif = p1.x - p2.x;
 int ydif = p1.y - p2.y;
 int dist = sqrt(xdif * xdif + ydif * ydif);
 return dist;
}
int eq(POINT p1, POINT p2)
// Struct Packet Exersize 5
{
 int xdif = (p1.x - p2.x);
 int ydif = (p1.y - p2.y);
 if (xdif < .00001 && xdif > -.00001 && ydif < .00001 && ydif > -.00001)
  return 1;
 else
  return 0;
}
struct RECT {
 POINT tl; //top left
 POINT br; //bottom lright
};// make sure that the rectangle maintains the properties of a rectangle
int rectArea(RECT input)
// Struct Packet Exercise 6
{
 int xdif = (input.tl.x - input.br.x);
 int ydif = (input.tl.y - input.br.y);
 int area = xdif * ydif;
 return area;
}
int ptInRect(POINT input, RECT rect)
// Struct Packet Exercise 7
{
 if (input.x <= rect.tl.x && input.x >= rect.br.x
  && input.y <= rect.tl.y && input.y >= rect.br.y)
  return 1;
 else
  return 0;
}
int rectInRect(void)
// Struct Packet Exercise 8 and 9
{
 RECT one = { {5,9}, {2,3} };
 RECT two = { {4,5}, {2,3} };
 if (one.tl.x <= two.tl.x && one.tl.x >= two.br.x
  && one.tl.y <= two.tl.y && one.tl.y >= two.br.y
  && one.br.x <= two.tl.x && one.br.x >= two.br.x
  && one.br.y <= two.tl.y && one.br.y >= two.br.y)
  return 1;
 else
  return 0;
 int area1 = rectArea(one);
 int area2 = rectArea(two);
 if (area1 > area2)
  printf("The first rectangle is bigger");
 else if (area2 > area1)
  printf("The second rectangle is bigger");
 else
  printf("Both of the rectangles are equal in size.");
}
int farthestPt(POINT* array)
// Struct Packet Exercise 10
{
// POINT array[5] = { {1,5}, {2,3}, {4,7}, {0,2}, {1,3} }; // make as if n number of points are inputted
 int dist = 0;
 int fardist = 0;
 POINT *p1, *p2;
 for (int a = 0; a <= 4; a++)
 {
  for (int b = 0; b <= 4; b++)
  {
   dist = ptdist(array[a], array[b]);
   if (dist >= fardist)
   {
    fardist = dist;
    p1 = &array[a];
    p2 = &array[b];
   }
  }
 }
 printf("The two farthest points are %f and %f. ", *p1, *p2);
 return 0;
}
int overlap(void)
// Struct Packet Exercise 11
{
 
}
struct BOX{
 int h; //height
 int w; //width
 int d; //depth
};

int getVolume(BOX x)
// Struct Packet Exercise 12
{
 int volume = x.h * x.w * x.d;
 return volume;
}
int smallestDiameter(BOX x)
// Struct Packet Exercise 13
{
 int smallest = x.h;
 if (x.w > x.h)
 {
  smallest = x.w;
  if (x.d > x.w)
   smallest = x.d;
 }
 else if (x.d > x.h)
  smallest = x.d;
 return smallest;
}

int main(void)
{
 ptInRect();
 //POINT *array = (POINT*)malloc()
 system("pause");
}

