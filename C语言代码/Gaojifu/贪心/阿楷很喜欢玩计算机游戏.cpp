#include<stdio.h>
#include<stdlib.h>
int treearr[1510];
int yezi[1510];
int ntreearr[1510][1500];
int boder[1510];
int flag[1510];
int ans;
void DFS(int x)
{
	if(boder[x]<=0)
		return ;
	for(int i=0;i<boder[x];i++)
	{
		DFS(ntreearr[x][i]);
	}
	int tempflag=0;
	for(int i;i<boder[x];i++)
	{
		if(!flag[ntreearr[x][i]])
		{
			tempflag=1;
			break;
		}
	}
	if(tempflag)
	{
		ans++;
		flag[x]=1;
	}	
}
int main()
{
	int t;
	while(~scanf("%d",&t))
	{
		ans=0;
		int temp=0;
		int  flag01=0;
		for(int i=0;i<1510;i++)
		{
			yezi[i]=-1;
			flag[i]=0;
			boder[i]=0;
		}
		int m,n;
		int ads=0;
		for(int i=0;i<t;i++)
		{
			scanf("%d:(%d)",&m,&n);
			if(flag01==0)
			{
				ads=m;
				flag01=1;
			}	
			int son;
			int j;
			for(j=0;j<n;j++)
			{
				scanf("%d",&son);
				treearr[son]=m;
				ntreearr[m][j]=son;
			}
			boder[m]=j;
		}
		DFS(ads);
		printf("%d\n",ans);
	}
	return 0;
}
