#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int arr[1000000];
char flag[10];
int n,m;
int lowbit(int x)
{
	return x&(-x);
}
void add(int pos,int val)
{
	while(pos<=n)
	{
		arr[pos]^=val;
		pos+=lowbit(pos);
	}	
}
int getsum(int pos)
{
	int sum=0;
	while(pos)
	{
		sum^=arr[pos];
		pos-=lowbit(pos);
	}
	return sum;
}
int main()
{
	int a,a1,a2;
	while(~scanf("%d%d",&n,&m))
	{
	memset(arr,0,sizeof(arr));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		add(i,a);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%s",flag);
		if(strcmp(flag,"Change")==0)
		{
			scanf("%d%d",&a1,&a2);
			a2^=arr[a1];
			add(a1,arr[a1]^a2);
		}
		else
		{
			scanf("%d%d",&a1,&a2);
			printf("%d\n",getsum(a2)^getsum(a1-1));
		}
	}	
	}
	return 0;
} 
