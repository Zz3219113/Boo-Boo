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
	int x,y,far;
}arr[5000];
int a[10000];
bool cmp(node x,node y)
{
	return x.far<y.far;
}
int find(int x)
{
	int t=x;
	if(a[t]==x)	return t;
	return a[t]=find(a[t]);//Â·¾¶Ñ¹Ëõ 
}
int main()
{
	int n,x,y,f1,f2;
	while(~scanf("%d",&n))
	{
		if(n==0)
			return 0;
		for(int i=1;i<=n;i++)
		{
			a[i]=i;
		}
		int t=n*(n-1)/2,cost,sum=0;
		for(int i=0;i<t;i++)
		{
			scanf("%d%d%d",&x,&y,&cost);
			if(x>y)
			{
				int temp;
				temp=x;
				x=y;
				y=temp;
			}
			arr[i].x=x;
			arr[i].y=y;
			arr[i].far=cost;
		}
		sort(arr,arr+t,cmp);
		for(int i=0;i<t;i++)
		{
			f1=find(arr[i].x);
			f2=find(arr[i].y);
			if(f1!=f2)
			{
				sum+=arr[i].far;
				a[f1]=f2;
			}
		}
		printf("%d\n",sum);
	}
} 
