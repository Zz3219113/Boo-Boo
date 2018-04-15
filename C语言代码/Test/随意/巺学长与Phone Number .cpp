#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
char a1[10];
int a[10];
int dir[4]={1,-1,-3,3};

int juge(int x)
{
	if(x>=1&&x<=9||x==11)
		return 1;
	else
		return -1;
}
int main()
{
	int n;
	loop:while(~scanf("%d",&n))
	{
		int count[4];
		int flag=1,cnt=0;
		memset(a1,0,sizeof(a1));
		memset(count,0,sizeof(count));
		memset(a,0,sizeof(a));
		scanf("%s",a1);
		for(int i=0;i<n;i++)
		{
			a[a1[i]-'0']=1;
			switch(a[i])
			{
				case 1:{
					count[3]++;
					count[2]++;
					break;
				}
				case 2:{
					count[1]++;
					count[2]++;
					count[3]++;
					break;
				}
				case 3:{
					count[2]++;
					count[1]++;
					break;
				}
				case 4:{
					count[0]++;
					count[1]++;
					count[3]++;
					break;
				}
				case 5:{
					count[0]++;
					count[1]++;
					count[2]++;
					count[3]++;
					break;
				}
				case 6:{
					count[0]++;
					count[1]++;
					count[2]++;
					break;
				}
				case 7:{
					count[0]++;
					count[3]++;
					break;
				}	
				case 8:{
					count[0]++;
					count[1]++;
					count[2]++;
					count[3]++;
					break;
				}
				case 9:{
					count[0]++;
					count[2]++;
					break;
				}
				case 0:{
					count[0]++;
					break;
				}
			}
		}
		for(int i=0;i<4;i++)
		{
			if(count[i]==n)
			{
				printf("NO\n");
				goto loop;
			}
		}
		printf("YES\n");
	}
	return 0;
}
