#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
char map[5][5];
int x,y;
int juge()
{
	int xa=0,xb=0,ya=0,yb=0;
	for(int i=0;i<4;i++)
	{
		int ha=0,hb=0,la=0,lb=0;
		if(map[i][i]=='x')
			xa++;
		if(map[i][i]=='o')
			xb++;
		if(map[3-i][i]=='x')
			ya++;
		if(map[3-i][i]=='o')
			yb++;
		for(int j=0;j<4;j++)
		{
			if(map[i][j]=='x')
				la++;
			else if(map[i][j]=='o')
				lb++;
			if(map[j][i]=='x')
				ha++;
			if(map[j][i]=='o')
				hb++;
		}
		if(xa==4||ya==4||ha==4||la==4)
			return 1;
		if(xb==4||yb==4||hb==4||lb==4)
			return -1;
	}
	return 0;
}
int alpha_beta(int player,int alpha,int beta)
{	int flag=juge();
	if(flag!=0)
		return flag;
	if(player==0)
	{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				if(map[i][j]=='.')
				{
					map[i][j]='x';
					int val=alpha_beta(player^1,alpha,beta);
					map[i][j]='.';
					if(val>alpha)
					{
						alpha=val;
						y=i;
						x=j;
					}		
					if(alpha>=beta)
						return alpha;
				}
			}
			return alpha;
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(map[i][j]=='.')
				{
					map[i][j]='o';
					int val=alpha_beta(player^1,alpha, beta);
					map[i][j]='.';
					if(val<beta)
						beta=val;
				}
				if(alpha>=beta)
					return beta;
			}	
		}
		return beta;
	}	
}
int main()
{
	char t;
	while(~scanf("%c",&t))
	{
		int player=0;
		int	cnt=0;
		getchar();
		if(t=='$')
			break;
		for(int i=0;i<4;i++)
		{
			gets(map[i]);
			for(int j=0;j<4;j++)
			if(map[i][j]!='.')
				cnt++;
		}
		if(cnt<=4)
		{
			printf("#####\n");
			continue;
		}
		int end=alpha_beta(player,-1,1);
		if(end>0)
		printf("(%d,%d)\n",y,x);
		else
		{
			printf("#####\n");
		}
	}
	return 0;
}

