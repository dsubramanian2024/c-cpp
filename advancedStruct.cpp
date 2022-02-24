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
Struct and Union Packet Exercise 1
1. 12
2. 12
3. 8
*/
//EM: GOOD
void socialsec(void)
// Exercise 2
{
	/*union {
		unsigned char arr[6];
		struct {
			unsigned short reg; //2 bytes
			unsigned char group; // 1 byte + 1 byte of padding
			unsigned short serial; //2 bytes
		}ssn;
	}u;*/

	union {
		unsigned char arr[11];
		struct {
			unsigned char reg[3];
			unsigned char deliminator;
			unsigned char group[2];
			unsigned char deliminator2;
			unsigned char serial[5];
		}ssn;
	}u;

	printf("Enter your SSN (###-##-####) :"); 
	scanf("%s", u.arr);
/*
	for (int i = 0; i < 6; i++) //individually read in the input as numbers into the array, DO NOT INPUT INT AS ELEMENTS CUZ SAVE AS
	{
		u.arr[i] = getchar();
		if (u.arr[i] < 0 || u.arr[i] > 9)
		{
			i--; //ignores all other characters like spaces and '#'
		}
	}
	printf("%d", u.arr);*/
	//scanf("%d-%d-%d", &u.ssn.reg, &u.ssn.group, &u.ssn.serial);

	printf("Region: %d\n", u.ssn.reg);
	printf("Group: %d\n", u.ssn.group);
	printf("Serial Number: %d", u.ssn.serial);
}

//EM: GOOD
int checkhex(int num)
//check to see if num is hex
{
	char str[2];
	sprintf(str, "%x", num);
	if (isxdigit(str[0]) > 0 && isxdigit(str[1]) > 0)
		return num;
	else
		return -1;
}
 
//EM: GOOD
unsigned char ubyte;
void makeColor(ubyte *red, ubyte *green, ubyte *blue)
// Exercise 4
{
	union {
		unsigned char rgb[3];
		struct {
			unsigned char blue; //one byte - up to 255
			unsigned char green;
			unsigned char red;
		}color;
	}u;

	printf("Enter an RGB value: ");
	scanf("%d", u.rgb);
	//scanf("%2x%2x%2x", &u.color.red, &u.color.green, &u.color.blue);
	//check to make sure all inputs are correct
	u.color.red = checkhex(u.color.red);
	u.color.green = checkhex(u.color.green);
	u.color.blue = checkhex(u.color.blue);
	*red = u.color.red;
	*green = u.color.green;
	*blue = u.color.blue;
}

void printcard(int num)
{
	char valarr[13] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A' };
	char suitarr[4][10] = { "Club", "Spade", "Heart<3", "Diamond<>" };
	printf("%s  %s", suitarr[num % 4], valarr[num % 13]);
}


// EM:  the index of the array [i] ; fixed

void cards(void)
//Exercise 5 
{
	int arr[52];
	for (int i = 0; i < 52; i++)
		arr[i] = i;

	int high = 51;
	while (high > 0)
	{
		int r = rand() % high;
		//printf(" r = ", r);
		int temp = arr[r];
		arr[r] = arr[high];
		arr[high] = temp;
		high -= 1;
	}
	//use random to choose from suit and number and make sure to remove card from deck so no repetition
	
	for (int i = 0; i < 52; i++)
	{
		printf("%d ", arr[i]);
	}

	return;
}

// EM (10/2) -   see comment ;fixed
void permission(void)
//Exercise 7
{
	union {
		unsigned char rwx[3];
		struct {
			unsigned char read;
			unsigned char write;
			unsigned char exe;
		}x;
	}num;

	printf("Enter the permission: ");
	int i = 0;
	while (((num.rwx[i] = getchar()) != '\n') && i < 3)
		i++;
	num.rwx[3] = NULL;

	
	char canString[][10] = { "cannot", "can" };

	printf("%s read", canString[num.x.read]);
	printf("%s write", canString[num.x.write]);
	printf("%s execute", canString[num.x.exe]);
}

struct DOB
{
	char month[2];
	char dash1;
	char day[2];
	char dash2;
	char year[4];
	char filler = 0;
};

int datenum(DOB date)
// exercise 9 book exercise 5a
{
	char* num = (char*)malloc(sizeof(DOB));
	num = strcpy(num, date.year);
	num = strcpy(num, date.month);
	num = strcpy(num, date.day);
	return atoi(num);
}

int compareDate(DOB date1, DOB date2)
// exercise 9 book exercise 5b
{
	return datenum(date1) - datenum(date2);
}

struct tm
{
	int tm_sec;
	int tm_min;
	int tm_hour;
};

struct tm split_time(long totalsec)
// exercise 9 book exercise 6
{
	tm time;
	time.tm_hour = totalsec % 3600;
	totalsec = totalsec - (time.tm_hour * 3600);
	time.tm_min = totalsec % 60;
	totalsec = totalsec - (time.tm_min * 60);
	time.tm_sec = totalsec;
	return time;
}
/*
struct frac(int num, int denom)
{
	int f1, f2;
	frac(double d1, double d2)
	{
		f1 = d1;
		f2 = d2;
	}
	double add()
	{ 
		f1 + f2;
	}
};*/

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	if (a == b)
		return a;

	if (a > b)
		return gcd(a - b, b);
	return gcd(b - a, a);
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

struct frac
{
	int num;
	int denom;
};

frac simplifyfrac(frac a)
{
	int d = gcd(a.num, a.denom);
	return frac{ a.num / d, a.denom / d};
}

frac fracAdd(frac a, frac b)
{ //still have to finish
	a = simplifyfrac(a);
	b = simplifyfrac(b);
	int d = lcm(a.denom, b.denom);
	int totalnum = (a.num * (d / a.denom)) + (b.num * (d / b.denom));
	return frac{ totalnum, d };
}

frac fracSub(frac a, frac b)
{
	b.num *= -1;
	return fracAdd(a, b);
}

frac fracMult(frac a, frac b)
{
	return simplifyfrac(frac{a.num * b.num, a.denom * b.denom});
}

frac fracDivide(frac a, frac b)
{
	int temp = b.denom;
	b.denom = b.num;
	b.num = temp;
	return fracMult(a, b);
}



struct color {
	int red;
	int green;
	int blue;
};

//exercise 9 book exercise 8a 
color magenta = { 255, 0, 255 };

struct color make_color(int red, int green, int blue)
// exercise 9 book exercise 9a
{
	color rgb = { red, green, blue };
	return rgb;
}

int get_red(struct color c)
// exercise 9 book exercise 9b
{
	return c.red;
}

//EM: easier to just use memcmp ; fixed
bool equal_color(struct color a, struct color b)
// exercise 9 book exercise 9c
{
	if (memcmp(&a, &b, sizeof(color)) == 0)
		return true;
	return false;
}

struct color brighter(struct color c)
	// exercise 9 book exercise 9d
{
	if (c.red < 3 && c.red > 0)
		c.red = 3;
	c.red = c.red / .7;
	if (c.red > 255)
		c.red = 255;
	if (c.green < 3 && c.green > 0)
		c.green = 3;
	c.green = c.green / .7;
	if (c.green > 255)
		c.green = 255;
	if (c.blue < 3 && c.blue > 0)
		c.blue = 3;
	c.blue = c.blue / .7;	
	if (c.blue > 255)
		c.blue = 255;
	if (c.red == 0 && c.green == 0 && c.blue == 0)
		c = { 3, 3, 3 };
	return c;
}

/*
Exercise 9
Chapter 16 Question 13
(a) legal
(b) legal
(c) s.u.rectangle.height
(d) legal
(e) s.u.circle.radius = 5
(f) s.u.circle.radius = 5
*/

struct point { int x, y; };

enum {RECTANGLE, CIRCLE};

struct shape {
	int shape_kind; // use constructor either RECTANGLE or CIRCLE
	point center;
	union {
		struct {
			int height, width;
		}rectangle;
		struct {
			int radius;
		}circle;
	}u;
};


int area(struct shape s)
// exercise 9 book exercise 14a
{
	if (s.shape_kind == RECTANGLE)
		return (s.u.rectangle.height * s.u.rectangle.width);
	else
		return (s.u.circle.radius * s.u.circle.radius * 3.14);
}




int main(void)
{
	/*
	ubyte *red = (ubyte *)malloc(sizeof(ubyte));
	ubyte *green = (ubyte *)malloc(sizeof(ubyte));
	ubyte *blue = (ubyte *)malloc(sizeof(ubyte));
	makeColor(red, green, blue);
	printf("%d  %d  %d", *red, *green, *blue);
	*/
	//socialsec();
	//permission();
	cards();
	system("pause");
}

