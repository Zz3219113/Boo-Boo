#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
long long len,num,time;
long long stone[500010];
long long far[500010];
long long bsearch(long long left,long long right)
{
	long long mid,ret=-1;
	while(left<right)
	{ 
		long long  count=1;
		long long cnt=0;
		mid=left+(right-left)/2;
		for(int i=num;i>=0;i--) 
		{
			if(cnt+far[i]<=mid)
				cnt+=far[i];
			else
			{
				cnt=far[i];
				count++;
			}
		}	
		if(count<=time)
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
	while(~scanf("%lld %lld %lld",&len,&num,&time))
	{
		long long max=-1;
		long long min=0x3f3f3f3f;
		for(long long i=0;i<num;i++)
		{
			scanf("%lld",&stone[i]);
		}
		sort(stone,stone+num);
		for(long long i=0;i<num;i++)
		{
			if(i==0)
				far[0]=stone[0];
			else
				far[i]=stone[i]-stone[i-1];
			if(max<far[i])
				max=far[i];
		}
		far[num]=len-stone[num-1];
		long long ans=bsearch(max,len);
		printf("%lld\n",ans);
	}
	return 0;
}
