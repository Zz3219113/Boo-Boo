#include<stdio.h>
#include<string.h>
#include<math.h>
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
	int a1,a2,a3,a4,fm,fz;
	char f;
	scanf("%d/%d%c%d/%d",&a1,&a2,&f,&a3,&a4);
	if(f=='+')
	{
		fm=a2*a4/GCD(a2,a4);
		fz=fm/a2*a1+fm/a4*a3;
		if(GCD(fz,fm)!=1)
		{	
			int yushu=GCD(fz,fm);
			fm/=yushu;
			fz/=yushu;
		}
		printf("%d/%d\n",fz,fm);
	}
	if(f=='-')
	{
		fm=a2*a4/GCD(a2,a4);
		fz=fm/a2*a1-fm/a4*a3;
		if(fz==0)
		{
			printf("0\n");
		}
		else
		{
			if(GCD(fz,fm)!=1)
			{	
				int yushu=GCD(fz,fm);
				fz/=yushu;
				fm/=yushu;
			}
			printf("-%d/%d\n",fz,-fm);
		}
	}
	return 0;
}

