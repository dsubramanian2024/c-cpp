# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>
# include <stdbool.h>
# include <time.h>
# include <string.h>

struct pinball_machine {
 // chapter 16 Exercise 19
 char name[40];
 int year; //year of manufacture
 enum type {EM, SS}; //electromechanical and solid state
 int players; //maximum number of players
};
int NESW(void)
// Chapter 16 Exercise 20
{
 int x = 0;
 int y = 0;

 enum {NORTH, SOUTH, EAST, WEST} direction;
 switch (direction) {
  case WEST : x--;
  case EAST: x++;
  case 1: y++;
  case 0: y--;
  default:;
 }
 return 0;
}
/*
Chapter 16 Exercise 21
(a) {0,1,2,3}
(b) {11,12,13}
(c) {14,15,16,24,25}
(d) {45,46,47,37,38,39}
*/

int chess(void)
// Chapter 15 Exercise 22 a
{
 enum chess_pieces { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN } a;
 a = KING;
 const int piece_value[6] = { 200, 9, 5, 3, 3, 1 };
 for (int x = 0; x <= 5; x++)
 {
  //a = piece_value[x];
  //a++;
 }
 return 0;
}

int getnum(void)
{
 int num = 0;
 char ch;
 while ((ch = getchar()) != '\n')
 {
  num *= 10;
  num += ch - '0';
 }
 return num;
} 

#define N  0

enum color { R, G, B };

int colors(void)
//Enum Packet Question 2
{
 printf("Enter R: ");
 0 = getnum();
 printf("Enter G: ");
 G = getnum();
 printf("Enter B: ");
 B = getnum();
 
 bool x = (G / R > 2);
 bool y = (G / B > 2);
 bool z = (B / R > 2);
 bool a = (B / G > 2);
 bool b = (R / G > 2);
 bool c = (R / B > 2);
 //need to find away to see if it is black or white without using if statements
 int total = x * 100000 + y * 10000 + z * 1000 + a * 100 + b * 10 + c;
 if (R < 50 && G < 50 && B < 50)
  printf("Black");
 else if (R > 200 && G > 200 && B > 200)
  printf("White");
 else(
  switch (total) {
   case 110000:
    printf("Green");
   case 11:
    printf("Red");
   case 1100:
    printf("Blue");
   default:
    printf("Unknown");
  }
 )
 return 0;
}

int directions(void)
// Enum Packet Question 3
{
 enum Directions {N, NE, E, SE, S, SW, W, NW};
 char dir[][10] = { "North", "NorthEast", "East", "SouthEast", "South", "SouthWest", "West", "NorthWest" };
 for (int i = N; i <= NW; i++)
  printf("%s == %d\n", dir[i], i*45);
 return 0;
}
int main(void)
{
 colors();
 system("pause");
}


