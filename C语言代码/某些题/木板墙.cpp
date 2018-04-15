#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
int arr[100010];
int l[100010];
int r[100010];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		long long sum=0;
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int j;
		for(int i=0;i<n;i++)
		{
			for(j=i-1;j>=0;j--)//
			{
				if(arr[j]>arr[i]&&l[j]==-1)
				{
					j=-1;
					break;
				}
				if(arr[j]>=arr[i])
				{
					j=l[j]+1;
					continue;	
				}
				else
					break;
			}
			l[i]=j;
		}
		for(int i=n-1;i>=0;i--)
		{
			for(j=i+1;j<n;j++)//
			{
				if(arr[j]>arr[i]&&r[j]==n)
				{
					j=n;
					break;
				}				
				if(arr[j]>=arr[i])
				{
					j=r[j]-1;
					continue;
				}
				else
					break;
			}
			r[i]=j;		
		}
		for(int i=0;i<n;i++)
		{
			if(arr[i]==arr[i-1])
				continue;
			long long temp1=arr[i];
			long long temp2=(r[i]-l[i]-1);
			long long temp=temp1*temp2;
			if(sum<temp)
				sum=temp;
		}		
		printf("%lld\n",sum);
	}
	return 0;
}
