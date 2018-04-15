#include<stdio.h>
#include<string.h>
#define MAXN 35
int N,K,len1[MAXN],len2[MAXN];
long long dp1[MAXN][MAXN*MAXN],dp2[MAXN][MAXN*MAXN];
long long cont[10][100];
void init()
{
    len1[1]=len1[2]=1;
    len2[1]=len2[2]=2;
    for(int i=3;i<MAXN;i++){
        len1[i]=len1[i-2]+2;
        len2[i]=len2[i-2]+2;
    }
}
int main()
{
    init();
    Loop:while(scanf("%d%d",&N,&K),N||K)
	{
		if(cont[N][K]!=0)
		{
			printf("%lld\n",cont[N][K]);
			goto Loop;
		}	
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(int i=0;i<=N;i++) 
			dp1[i][0]=dp2[i][0]=1;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=K;j++)
			{
                dp1[i][j]=dp1[i-1][j]+(len1[i]-j+1)*dp1[i-1][j-1];
                dp2[i][j]=dp2[i-1][j]+(len2[i]-j+1)*dp2[i-1][j-1];
            }
        long long ans=0;
        	for(int i=0;i<=N;i++) 
				ans+=dp1[N][i]*dp2[N-1][K-i];
			cont[N][K]=ans;
			printf("%lld\n",ans);      	
    }
    return 0;
}

