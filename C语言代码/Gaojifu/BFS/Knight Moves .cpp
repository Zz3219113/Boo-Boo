#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int dir[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}};
int flag[8][8];
struct node
{
	int x,y,step;
	
};
int main()
{
	char a,b,c,d;
	while(~scanf("%c%c %c%c",&a,&b,&c,&d))
	{
	getchar();
	node N,P;
	queue<node>Q;
	memset(flag,0,sizeof(flag));
	int r1=a-'a';
	int r2=b-'1';
	int r3=c-'a';
	int r4=d-'1';
	N.x=r1,N.y=r2,N.step=0;
	Q.push(N);
	flag[r1][r2]=1;
	while(!Q.empty())
	{
		N=Q.front();Q.pop();
		if(N.x==r3&&N.y==r4)
			break;
		for(int i=0;i<8;i++)
		{
			int tx=N.x+dir[i][0];
			int ty=N.y+dir[i][1];
			if(tx>=0&&tx<8&&ty>=0&&ty<8&&flag[tx][ty]==0)
			{
				P.y=ty;
				P.x=tx;
				P.step=N.step+1;
				Q.push(P);
				flag[tx][ty]=1;
			}
		}
	}
	printf("To get from %c%c to %c%c takes ",a,b,c,d);
	printf("%d knight moves.\n",N.step);
	}
 	return 0;
}

