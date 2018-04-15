#include<stdio.h>
#include<string.h>
#include<math.h>
double Y;
bool fun(double x)
{
	if((8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*pow(x,1)+6)>Y) 
		return true;
	else
		return false;
}
double yfun(double x)
{
	double y;
	return y=8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*pow(x,1)+6;
}
double bsearch(double L,double R)
{
	int i;
	double mid;
	for(i=0;i<150;i++)
	{
		mid=(double)(L+R)/2;
		if(fun(mid))
			R=mid;
		else
			L=mid;
	}
	return mid;
}
int main()
{
	double L=0,R=100,x;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&Y);
	if(Y<26||Y>807020306)
		printf("No solution!\n");
	else
		printf("%0.4lf\n",bsearch(L,R));
	}
	return 0;
}
