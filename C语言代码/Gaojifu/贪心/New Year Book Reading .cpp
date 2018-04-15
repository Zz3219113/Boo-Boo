#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int flag[510],arr[510],order[510],brr[1010];
int main()
{
	int n,m,cnt=0,temp,res=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int j=0;j<m;j++)
	{
		scanf("%d",&temp);
		brr[j]=temp;
		if(flag[temp]==0)
		{
			order[cnt++]=temp;
			flag[temp]=1;
		}
	}
	int ans=0;
	for(int i=0;i<m;i++)
	{
		int sum=0;
		for(int j=0;j<cnt;j++)
		{
			
			sum+=arr[order[j]];
			if(order[j]==brr[i])
			{
				ans+=sum-arr[order[j]];
				if(j!=0)
					for(int k=j-1;k>=0;k--)
					{
						order[k+1]=order[k];
					}
				order[0]=brr[i];
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
