#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int dp[2500][2500];
char a1[2500],a2[2500];
int main()
{
	while(~scanf("%s %s",a1+1,a2+1))
	{
		memset(dp,0,sizeof(dp));
		int len1=strlen(a1+1);
		int len2=strlen(a2+1);
		for(int i=1;i<=len1;i++)
			for(int j=1;j<=len2;j++)
			{
				if(a1[i]==a2[j])
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		printf("%d\n",dp[len1][len2]);			
	}
	return 0;
} 
