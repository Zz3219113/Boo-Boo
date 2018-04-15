#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
long long n,m;
long long	res[20010],b[20010],c[20010],a[20010];
long long bsearch(long long left,long long right)
{
	long long mid,ret=-1;
	while(left<right)
	{ 
		long long  count=1;
		long long cnt=0;
		mid=left+(right-left)/2;
		for(int i=n-1;i>=0;i--) 
		{
			if(cnt+arr[i]<=mid)
				cnt+=arr[i];
			else
			{
				cnt=arr[i];
				count++;
			}
		}	
		
		if(count<=m)
		{
			right=mid;
		}			
		else
			left=mid+1;
		ret=left; 
	}
	return ret;
}
int main()
{
	int t;
	while(scanf("%d",&t))
	{	
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		long long i,j;
		for(i=0;i<t;i++)
		{
			scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
			for(j=a[i];j<=b[i];j+=c[i])
			{
				res[j]++;
				sum++;
			}
		}
		
	return 0;
} 
