#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int n;
int stick[100010],xx;
int main()
{
	loop:while(~scanf("%d",&n))
	{
		memset(stick,0,sizeof(stick));
		for(int i=0;i<n;i++)//1e5
		{
			scanf("%d",&stick[i]);
		}
		sort(stick,stick+n);
		for(int i=n-1;i>=2;i--)
		{
			if(stick[i]-stick[i-1]<stick[i-2])
			{
				printf("愚蠢的学长啊\n");
				goto loop;
			}
		}
		printf("我也很绝望啊\n");
	}
	return 0;
}
