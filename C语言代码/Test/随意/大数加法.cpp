#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int b1[1010],b2[1010],sum[1010];
int main()
{
	char a1[1010],a2[1010];
	int n,t,i,carry,len1,len2;
	scanf("%d",&t);
	int N=t;
	while(t--)
	{
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		memset(sum,0,sizeof(sum));
		scanf("%s %s",a1,a2);
		len1=strlen(a1);
		len2=strlen(a2);
		for(i=0;i<len1;i++)
		{
			b1[1000+i-len1]=a1[i]-'0';
		}
		for(i=0;i<len2;i++)
		{
			b2[1000+i-len2]=a2[i]-'0';
		}
		for(i=1000;i>=0;i--)
		{
			sum[i]+=b1[i]+b2[i];
			if(sum[i]>=10)
			{
				sum[i-1]+=sum[i]/10;
				sum[i]%=10;
			}
		}
		for(i=0;i<1000;i++)
		{
			if(sum[i]!=0)
			break;
		}
		printf("Case %d:\n",(N-t));
		if(i==1000)
		{
			printf("%s + %s = 0\n",a1,a2);
		}
		else
		{
			printf("%s + %s = ",a1,a2);
			for(int j=i;j<=999;j++)
			{
				printf("%d",sum[j]);
			}
			printf("\n");
		}		
		if(t>0)
			printf("\n");
	} 
 	return 0;
}

