#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int wall[110];
int map[110][110];
int main()
{
	int t,n,m,x1,x2,y1,y2;
	scanf("%d",&t);
	while(t--)
	{
		int minx=0x3f3f3f3f,miny=0x3f3f3f3f,maxx=-1,maxy=-1;
		memset(wall,0,sizeof(wall));
		memset(map,0,sizeof(map));
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1>x2)
			{
				int temp;
				temp=x1;
				x1=x2;
				x2=temp;
			}
			if(maxx<x2)
				maxx=x2;
			if(minx>x1)
				minx=x1;
			if(maxy<y2)
				maxy=y2;
			if(miny>y2)
				miny=y2;
			for(int j=x1;j<=x2;j++)
			{
				wall[j]++;
				map[y2][j]=i+1;
			}
		}
		int cnt=0;int maxcount=0,inx=-1,count;
		for(int i=minx;i<=maxx;i++)
		{
			while(wall[i]>m)
			{
				int ni;
				maxcount=0;
				for(int j=miny;j<=maxy;j++)
				{
					if(map[j][i]!=0)
					{
						count=0;
						ni=i+1;
						while(map[j][ni++]==map[j][i])
							++count;
						if(maxcount<count)
						{
							maxcount=count;
							inx=j;
						}
						
					}	
				}
				for(int k=i;k<=i+maxcount;++k)
				{
					map[inx][k]=0;	
					wall[k]--;
				}
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
