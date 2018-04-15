#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int m,n,max1[110],max2[110];
	char map[110][110];
	memset(max1,-1,sizeof(max1));
	memset(max2,-1,sizeof(max2));
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&map[i][j]);
			if(max1[i]<map[i][j])
				max1[i]=map[i][j];
		}
	}
	for(int j=0;j<n;j++)
		for(int i=0;i<m;i++)
			if(max2[j]<map[i][j])
				max2[j]=map[i][j];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(map[i][j]==max1[i]||map[i][j]==max2[j])
				continue;
			else
			{
				printf("NO\n");
				return 0;
			}
		}
	printf("YES\n");
	return 0;
}
