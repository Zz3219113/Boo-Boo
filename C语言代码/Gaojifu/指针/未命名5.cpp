#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	char a[1005];
	int n,i,j,k,length;
	long long b[1000],count=0,temp;
	while(~scanf("%s",a))
	{	length=strlen(a);
		i=0;
		j=0;
		a[length]='5';
		while(1)
		{
			if(a[i]=='5')
				i++;
			else
				break;
		}
		for(i;i<=length;i++)
		{
			if(a[i]=='5'&&a[i+1]=='5')
			{
				continue;
			}
			else if(a[i]!='5')
			{
				count=count*10+a[i]-'0';
			}
			else
			{
				b[j++]=count;
				count=0;	
			}	
		}
		if(j==1)
		{
			printf("%lld\n",b[0]);
		}
		else
		{
			
		
			for(i=0;i<j-1;i++)
			{
				for(k=0;k<j-i-1;k++)
				{
					if(b[k]>b[k+1])
					{
						temp=b[k+1];
						b[k+1]=b[k];
						b[k]=temp;
					}
				}
			}
			printf("%lld",b[0]);
			for(i=1;i<j;i++)
			{
				printf(" %lld",b[i]);
			}
			printf("\n");
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));	
	}
	return 0;
}

