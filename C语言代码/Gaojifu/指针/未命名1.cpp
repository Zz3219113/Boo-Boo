#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n,t,i,count,flag;
	char a[100000];
	scanf("%d",&t);
	while(t--)
	{	flag=0;
		memset(a,0,sizeof(a));
		scanf("%s %d",a,&n);
		count=strlen(a);
		for(i=0;i<count;i++)
		{
			if(a[i]=='.')
			{
				flag=i;
				break;
			}		
		}
		if((count-flag-1)>=n)
			printf("%c\n",a[flag+n]);
		else
			printf("0\n");
	}
	return 0;
}

