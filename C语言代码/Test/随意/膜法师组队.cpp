#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	char a[40][14];
	int n,i,j,k,e,flag1,flag2,count=0,len1,len2,sex[40];
	while(scanf("%d",&n)!=EOF)
	{
		flag1=n;
		flag2=n;
		memset(a,0,sizeof(a));
		memset(sex,0,sizeof(sex));
		count=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %s",&sex[i],a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(count==n*0.5)
			break;
		if(sex[i]==0)
			{
				for(j=n-1;j>=0;j--)
				{
					if(sex[j]==1)
					{
						printf("%s",a[i]);
						printf(" ");
						printf("%s",a[j]);
						printf("\n");
						count++;	
						sex[j]=2;
						break;
					}
				}	
			}
		if(sex[i]==1)
			{
				for(j=n-1;j>=0;j--)
				{
					if(sex[j]==0)
					{
						printf("%s",a[i]);
						printf(" ");
						printf("%s",a[j]);
						printf("\n");
						count++;
						sex[j]=2;
						break;
					}
				}
			}		
	}
	}
	return 0;
}
 	

