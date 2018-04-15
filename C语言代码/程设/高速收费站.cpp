#include<stdio.h>
#include<string.h>
int abs(int x)
{
	return x>0?x:-x;
}
int arr[1000010];
int main()
{
	int n,ans=0,pre=0,cur=0;
	memset(arr,0,sizeof(arr));
	scanf("%d",&n);	
	if(n==1)
	{
		scanf("%d",&arr[0]);
		printf("%d\n",arr[0]);
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[0]);
			arr[arr[0]]++;
		}	
		for(int i=1;i<=1000000;i++)
		{
			if(arr[i]==0)
				continue;
			if(arr[i]>0&&pre==0)
				pre=i;
			else if(arr[i]>0&&pre!=0)
			{
				if(ans<i-pre)
					ans=i-pre;
				pre=i;
			}
		}
			printf("%d\n",ans);
	}
	return 0;
}
