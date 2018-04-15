#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
struct node
{
	int bean,food;
	double per;
}x[1000];
int cmp(node x,node y)
{
	return x.per>y.per;
}
int main()
{
	int N,M;
	while(~scanf("%d%d",&M,&N))
	{
		double result=0;
		if(N==-1&&M==-1)
			break;
		for(int i=0;i<N;i++)
		{
			scanf("%d %d",&x[i].bean,&x[i].food);
			x[i].per=(double)x[i].bean/x[i].food;
		}	
		sort(x,x+N,cmp);
		for(int i=0;i<N;i++)
		{
			if(M>x[i].food)
			{
				result+=(double)x[i].bean;
				M=M-x[i].food;
			}
			else
			{
				result+=(double)M*x[i].per;
				break;
			}
		}
		printf("%.3lf\n",result); 
	}
	return 0;
} 

