#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int n;
long long a[20010],b[20010],c[20010],res[20010];
long long bsearch(long left,long right)
{
	long long mid,ret=-1;
	while(left<=right)
	{
		long long cnt=0;
		mid=left+(right-left)/2;
		for(int i=0;i<n;i++)
		{
			if(a[i]<=mid)
			{
				if(mid<b[i])
				{
					cnt+=(mid-a[i])/c[i]+1;
				}
				else
				{
					cnt+=(b[i]-a[i])/c[i]+1;
				}
			}
		}
		if(cnt%2==1)
		{
			ret=mid;
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	return ret;
}
int main()
{
	while(~scanf("%d",&n))
	{
		long long cnt=0;
		long long right=-1;
		long long left=0x3f3f3f3f;
		for(int i=0;i<n;i++)
		{
			scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
			if(right<b[i])
				right=b[i];
			if(left>a[i])
				left=a[i];
			cnt+=(b[i]-a[i])/c[i]+1;
		}
		if(cnt%2==0)
			printf("DC Qiang is unhappy.\n");
		else
		{
			long long ans=bsearch(left,right);
			long long num=0;
			for(int i=0;i<n;i++)
			{
				if((ans-a[i])%c[i]==0&&ans>=a[i]&&ans<=b[i])
					num++;
			}
			printf("%lld %d\n",ans,num);
		}
	}
	return 0;
}
