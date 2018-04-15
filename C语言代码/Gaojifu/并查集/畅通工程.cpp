#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int pre[1010];
int find(int x)
{
	int t=x;
	while(t!=pre[t])
		t=find(pre[t]);//Â·¾¶Ñ¹ËõËã·¨ 
	return t;
}
int main()
{
	int count,c1,c2,f1,f2,n,m;
	while(~scanf("%d",&n)&&n!=0)
	{	scanf("%d",&m);
		count=n-1;
		for(int i=1;i<=n;i++)
		{
			pre[i]=i;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&c1,&c2);
			f1=find(c1);
			f2=find(c2);
			if(f1!=f2)
			{
				pre[f1]=f2;
				count--;
			}
		}
		if(count<0)
			count=0; 
		printf("%d\n",count);
	}
	return 0;
}
