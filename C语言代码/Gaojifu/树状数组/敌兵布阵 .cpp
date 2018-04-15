#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int arr[50005];
char mode[10];
int n;
int lowbit(int x)
{
	return x&(-x);
}
void add(int pos,int val)
{
	while(pos<=n)
	{
		arr[pos]+=val;
		pos+=lowbit(pos);
	}	
}
int getsum(int pos)
{
	int sum=0;
	while(pos)
	{
		sum+=arr[pos];
		pos-=lowbit(pos);
	}
	return sum;
}
int main()
{
	int t,a1,a2,temp;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		printf("Case %d:\n",j);
		memset(arr,0,sizeof(arr));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			add(i,temp);
		}
		while(~scanf("%s",mode))
		{
			if(strcmp(mode,"End")==0)
				break;
			else
			{
				scanf("%d %d",&a1,&a2);
				if(strcmp(mode,"Add")==0)
				{
					add(a1,a2);
				}
				else if(strcmp(mode,"Sub")==0)
				{
					add(a1,-a2);
				}
				else
				{
					printf("%d\n",getsum(a2)-getsum(a1-1));
				}
			}
		}
	}
	return 0;
} 
