#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
int c[100010],n;
struct node
{
	int x,y,pos;
}arr[100010];
bool cmp(node x,node y)
{
	if(x.y!=y.y)return x.y>y.y;
	else if(x.y==y.y)
		return x.x<y.x;
}
int lowbit(int x)
{
	return x&(-x);
}
void add(int pos,int val)
{
	while(pos<=n)
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
	while(~scanf("%d",&n),n)
	{
		int ans[100010];
		memset(ans,0,sizeof(ans));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&arr[i].x,&arr[i].y);
			arr[i].pos=i;
		}
		sort(arr+1,arr+1+n,cmp);
		ans[arr[1].pos]=0;
		add(arr[1].x+1,1);
		for(int i=2;i<=n;i++)
		{
			if(arr[i].x==arr[i-1].x&&arr[i].y==arr[i-1].y)
				ans[arr[i].pos]=ans[arr[i-1].pos];
			else
				ans[arr[i].pos]=getsum(arr[i].x+1);
			add(arr[i].x+1,1);
		}
		printf("%d",ans[1]);
		for(int i=2;i<=n;i++)
		{
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
