#include <stdio.h>
int Sum(int a)
{
	auto int b = 0;
	static int c = 3;

	b = b + 1;
	c = c + 2;
	return (a + b + c);
}
void main()
{
	int a = 2, i = 0;
	for (i = 0; i < 3; i++)
		printf("%d",Sum(a));
}
