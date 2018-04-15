#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
int dp[101][101];      
struct node
{
    int exp;    
    int r;     
}a[101];

int main()
{
    int n,m,k,s,i,j,t;
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
    {
        for(i=1;i<=k;i++)
            scanf("%d%d",&a[i].exp,&a[i].r);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=k;++i)   
            for(j=a[i].r;j<=m;++j) 
                for(t=1;t<=s;++t)    
                {
                    if(dp[j][t]<dp[j-a[i].r][t-1]+a[i].exp)
                    {
                        dp[j][t]=dp[j-a[i].r][t-1]+a[i].exp;
                    }
                }
        if(dp[m][s]>=n)     
        {
                for(i=0;i<=m;++i)  
                    if(dp[i][s]>=n) 
                    {
                        printf("%d\n",m-i);
                        break;
                    }
        }
        else
            printf("-1\n");
    }
    return 0;
}
