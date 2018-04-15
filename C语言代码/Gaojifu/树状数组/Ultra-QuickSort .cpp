#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
int c[500005],reflect[500005],n;
struct node
{
	int pos,val;
}arr[500005];
bool cmp(node x,node y)
{
	return x.val<y.val;
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
		long long ans=0; 
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i].val);
			arr[i].pos=i;
		}
		sort(arr+1,arr+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			reflect[arr[i].pos]=i;
		}
		for(int i=1;i<=n;i++)
		{
			add(reflect[i],1);
			ans+=i-getsum(reflect[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
