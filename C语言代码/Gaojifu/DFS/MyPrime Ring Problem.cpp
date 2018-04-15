#include<stdio.h>
#include<string.h>
int prime[40]={0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0},n;
int flag[21],res[21];
void dfs(int len)
{
	int i;
	if(len==n&&prime[res[len-1]+res[0]])
	{
		for(i=0;i<len-1;i++)
			printf("%d ",res[i]);
		printf("%d\n",res[len-1]);
	}
	else
	{
		for(i=2;i<=n;i++)
		{
			if(flag[i]==0)
			{
				if(prime[i+res[len-1]])
				{
					flag[i]=-1;
					res[len++]=i;
					dfs(len);
					flag[i]=0;
					len--;
				}	
			}
		}	
	}
}
int main()
{ 
	int num=0;
	while(~scanf("%d",&n))
	{
		num++;
		printf("Case %d:\n",num);
		memset(flag,0,sizeof(flag));
		res[0]=1;
		dfs(1);
		printf("\n");
	}
	return 0;
}
