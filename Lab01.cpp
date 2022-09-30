#include <stdio.h>
#include <math.h>

int main()
{
	char c = 65;
	//ASCII code
	printf("%c\r\n", c);
	//numeric value
	printf("%d\r\n", c);
	c = -23;
	printf("%d\r\n", c);
	//integers overflow in C/C++
	unsigned char d = -120;
	printf("%d\r\n", d);
	printf("%d\r\n", sizeof(c));

	//sizes are different based on the
	//compiler used and the PC architecture
	short x = 258;
	printf("%d\r\n", sizeof(x));
	
	int y = 894234;
	printf("%d\r\n", sizeof(y));

	long long z = 8942342323;
	printf("%d\r\n", sizeof(z));

	float f = 8.4f;
	printf("%d\r\n", sizeof(f));

	double g = 9.234234;
	printf("%d\r\n", sizeof(g));

	//floating point numbers shouldn't
	//be compared with ==
	//they are just aproximations

	if (f == 8.4) //this is evaluated to false
	{
		printf("That's a bad idea!");
	}

	if (fabs(f - 8.4) < 0.01) 
	{
		printf("That's a good idea!");
	}
}