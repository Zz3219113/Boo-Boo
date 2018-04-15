#include<stdio.h>
#include<stdlib.h>
/*int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}*/ //MMP
int n,m;
long long sum,res,max;
long long arr[1010];
long long find(long long left,long long right)
{
	long long mid,ret=0;
	while(left<right)
	{
		mid=(right+left)/2;
		long long count1=0,count2=1;
		for(int i=0;i<n;i++)
		{
			if(count1+arr[i]<=mid)
				count1+=arr[i];
			else
			{
				count1=arr[i];
				count2++;
			}
		}
		if(count2<=m)
		{
			right=mid;
		}			
		else
			left=mid+1;
		ret=right;	
	}
	return ret;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		sum+=arr[i];
		if(max<=arr[i])
			max=arr[i];
	}
	if(n==m)
	{
		printf("%lld\n",max);
		return 0;
	}
	//qsort(arr,n,sizeof(arr[0]),cmp);  MMP
	res=find(max,sum);
	printf("%lld\n",res);
	return 0;
}
