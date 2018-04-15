#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
int n,c[32005];
int lowbit(int x)
{
	return x&(-x);
}
void add(int pos,int val)
{
	while(pos<=32005)
	{
		c[pos]+=val;
		pos+=lowbit(pos);
	}
}
int getsum(int pos)
{
	int sum=0;
	while(pos)
	{
		sum+=c[pos];
		pos-=lowbit(pos);
	}
	return sum;
}
int main()
{
	int x, y;
	while(~scanf("%d",&n))
	{
		int ans[15010];
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&y);
			ans[getsum(x+1)]++;
			add(x+1,1);
		}
		for(int i=0;i<n;i++)
		{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
