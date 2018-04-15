#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m;
int arr[12][110];
int minans;
int rout[110][10];
int ans[110],res;
void find(int x,int y,int temp,int brr[])
{
	if(x==-1)
	{
		x=n-1;
	}
	if(x==n)
	{
		x=0;
	}
	temp+=arr[x][y];
	brr[y]=x+1;
	if(y==m-1)
	{
		if(temp==minans)
		for(int i=0;brr[i]<=ans[i]&&i<m;i++)
		{
			if(brr[i]<ans[i])
			{
				memcpy(ans,brr,m*sizeof(brr[0]));
				break;
			}
		}
		else if(temp<minans)
		{
			minans=temp;
			memcpy(ans,brr,m*sizeof(brr[0]));
		}
		return ;
	}
	if(y<m)
	{
		if(temp<=minans)
		{
			find(x-1,y+1,temp,brr);
			find(x,y+1,temp,brr);
			find(x+1,y+1,temp,brr);
		}
	}
}
int main()
{
	Loop:while(~scanf("%d %d",&n,&m))
	{
		minans=2147483647;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		res=0;
		int brr[110];
		if(n==1)
		{
			for(int i=0;i<m;i++)
			{
				if(i==0)
					printf("1");
				else
					printf(" 1");
				printf("\n");
				minans+=arr[0][i];
			}
			printf("%d\n",res);
			goto Loop;
		}
		else
			for(int i=0;i<n;i++)
			{
				memset(brr,0,sizeof(brr));
				find(i,0,0,brr);
			}
		for(int i=0;i<m;i++)
		{
			if(i<m-1)
			printf("%d ",ans[i]);
			else
			printf("%d\n",ans[i]);
		}
		printf("%d\n",minans);
	}
	return 0;
}
