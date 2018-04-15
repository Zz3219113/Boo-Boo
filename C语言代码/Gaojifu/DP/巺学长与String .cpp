#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
int dp[110][110][110];
char a1[110],a2[110],a3[110];
int main()
{
	int  cnt=1;
	while(~scanf("%s %s %s",a1+1,a2+1,a3+1))
	{
		printf("Case %d: ",cnt++);
		memset(dp,0,sizeof(dp));
		int len1=strlen(a1+1);
		int len2=strlen(a2+1);
		int len3=strlen(a3+1);
		for(int i=1;i<=len1;i++)
			if(a1[i]>=65&&a1[i]<=90)
				a1[i]=a1[i]-'A'+'a';
		for(int j=1;j<=len2;j++)
			if(a2[j]>=65&&a2[j]<=90)
				a2[j]=a2[j]-'A'+'a';
		for(int k=1;k<=len3;k++)
			if(a3[k]>=65&&a3[k]<=90)
				a3[k]=a3[k]-'A'+'a';
		for(int i=1;i<=len1;i++)
			for(int j=1;j<=len2;j++)
			{
				for(int k=1;k<=len3;k++)
				{
					if(a1[i]==a2[j]&&a2[j]==a3[k])
					{
						dp[i][j][k]=dp[i-1][j-1][k-1]+1;
					}
					else
					{
						dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k]);
						dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]);
					}
				}
			}
			printf("%d\n",dp[len1][len2][len3]);		
	}
	return 0;
} 
