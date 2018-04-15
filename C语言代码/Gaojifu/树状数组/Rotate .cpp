#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
long long arr[10010];
int a[3000010];
int n;
long long ans;
int lowbit(int x)
{
	return x&(-x);
}
void add(int pos,int val)
{
	while(pos<=10000)
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
	int temp,ans=0,m,a1,a2;
	char c[2];
	while(~scanf("%d",&n))
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(arr,0,sizeof(arr));
		for(int i=1;i<=n;i++)
		{
			ans+=getsum(a[i]-1);
			add(a[i],1);
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",&c);
			if(c[0]=='Q')
			{
				printf("%d\n",ans);
				continue;
			}
			else
			{
				scanf("%d%d",&a1,&a2);
				if(a2<a1)
				{
					int temp;
					temp=a2;
					a2=a1;
					a1=temp;
				
				}
				int tem=a[a1];
				for(int i=a1+1;i<=a2;i++)
				{
					if(a[i]>tem)
						ans--;
					else if(a[i]<tem)
						ans++;
					a[i-1]=a[i];
				}
				a[a2]=tem;
			}
		}
		
	}
	return 0;
}
