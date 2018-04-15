#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int GCD(int a,int b)
{
	int temp;
	if(b>a)
	{
		temp=a;
		a=b;
		b=temp;
	}
	return a%b==0?b:GCD(b,a%b);
}
int main()
{
	printf("%d",GCD(4,4));
	return 0;
}

