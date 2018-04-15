#include <stdio.h>
#include <string.h>
void plus(char *a, char *b, char *c);
void minus(char *a, char *b, char *c);
void multiply(char *a, char *b, char *c);
int main()
{       
    char a[1000];
    char b[1000];
    char c[1000];
    char s[2];

    while (scanf("%s %s %s", a, s, b) == 3) {
        if (s[0] == '+') {
            plus(a, b, c);
        } else if (s[0] == '-') {
            minus(a, b, c);
        } else if (s[0] == '*') {
            multiply(a, b, c);
        }
        printf("%s\n", c);
    }
    return 0;
}
void plus(char *a, char *b, char *c)
{
	int arr1[1010],arr3[1010],res[1010];
	memset(arr1,0,sizeof(arr1));
	memset(arr3,0,sizeof(arr3));
	memset(res,0,sizeof(res));
	for(int j=0;j<1000;j++)
	{
		c[j]='\0';
	}
	int len1,len3,reals1,reals3,i;
	len1=strlen(a);
	len3=strlen(b);
	for(int i=0;i<len1;i++)
	{
		arr1[1000+i-len1]=a[i]-'0';
	}
	for(int i=0;i<len3;i++)
	{
		arr3[1000+i-len3]=b[i]-'0';
	}
	for(i=1000;i>=0;i--)
	{
		res[i]+=arr1[i]+arr3[i];
		if(res[i]>=10)
		{
			res[i-1]+=res[i]/10;
			res[i]%=10;
		}
	}
	for(i=0;i<1000;i++)
	{
		if(res[i]!=0)
		break;
	}
	if(i==1000)
	{
		c[0]='0';
	}
	else
	{
		for(int j=i;j<=999;j++)
		{
			c[j-i]=res[j]+'0';
		}
	}
}
void minus(char *a, char *b, char *c)
{
	int arr1[1010],arr3[1010],res[1010];
	char test[1010];
	int len1,len2,len3,flag=0,i,flag1=0,flag2=0;
	len1=strlen(a);
	len3=strlen(b);
	memset(arr1,0,sizeof(arr1));
	memset(arr3,0,sizeof(arr3));
	memset(res,0,sizeof(res));
	memset(test,0,sizeof(test));
	for(int j=0;j<1000;j++)
	{
		c[j]='\0';
	}
	for(int i=0;i<len1;i++)
	{
		arr1[1000+i-len1]=a[i]-'0';
		if(a[i]-'0'!=0)
			flag1+=1;
	}
	for(int i=0;i<len3;i++)
	{
		arr3[1000+i-len3]=b[i]-'0';
		if(b[i]-'0'!=0)
			flag2+=1;
	}
	if(flag1==0||flag2==0)
	{
		if(flag1==0&&flag2==0)
			c[0]='0';
		else if(flag1==0)
		{
			printf("-");
			for(i=0;i<1000;i++)
			{
				if(arr3[i]!=0)
				break;
			}
			if(i==1000)
			{
				c[0]='0';
			}
			for(int j=i;j<=999;j++)
			{
				c[j-i]=arr3[j]+'0';
			}
		}
		else
		{
			for(i=0;i<1000;i++)
			{
				if(arr1[i]!=0)
				break;
			}
			if(i==1000)
			{
				c[0]='0';
			}
			for(int j=i;j<=999;j++)
			{
				c[j-i]=arr1[j]+'0';
			}
		}
	}
	else
	{
		for(i=0;i<1000;i++)
		{
			if(arr1[i]>arr3[i])
			{
				flag=1;
				break;
			}
			if(arr1[i]<arr3[i])
			{
				flag=-1;
				break;
			}
		}
		switch(flag)
		{
			case 1://zhengshu
			{
				for(i=999;i>=1000-len1;i--)
				{
					res[i]+=arr1[i]-arr3[i];
					if(res[i]<0)
					{
						arr1[i-1]-=1;
						res[i]+=10;
					}
				}
				for(i=0;i<1000;i++)
				{
					if(res[i]!=0)
					break;
				}
				if(i==1000)
				{
					c[0]='0';
				}
				if(res[i]<0)
				{
					i++;
					for(int j=i;j<=999;j++)
					{
						c[j-i]=res[j]+'0';
					}
				}
				else			
				for(int j=i;j<=999;j++)
				{
					c[j-i]=res[j]+'0';
				}
				break;
			}
			case (-1)://fushu
			{
				for(i=999;i>=1000-len3;i--)
				{
					res[i]+=arr3[i]-arr1[i];
					if(res[i]<0)
					{
						arr3[i-1]-=1;
						res[i]+=10;
					}
				}
				for(i=0;i<1000;i++)
				{
					if(res[i]!=0)
					break;
				}
				if(i==1000)
				{
					c[0]='0';
				}
				else
				{
					if(res[i]<0)
					{
						printf("-");
						i++;
						for(int j=i;j<=999;j++)
						{
							c[j-i]=res[j]+'0';
						}
					}
					else
					{
						printf("-");
						for(int j=i;j<=999;j++)
						{
							c[j-i]=res[j]+'0';
						}
					}			
					
				}
				break;
			}
			case 0:
			{
				c[0]='0';
				break ;
			}
		}
	}
}
void multiply(char *a, char *b, char *c)
{
	int arr1[1010],arr3[1010],res[1010];
	memset(arr1,0,sizeof(arr1));
	memset(arr3,0,sizeof(arr3));
	memset(res,0,sizeof(res));
	for(int j=0;j<1000;j++)
	{
		c[j]='\0';
	}
	int len1,len3,reals1,reals3,i;
	len1=strlen(a);
	len3=strlen(b);
	for(int i=0;i<len1;i++)
	{
		arr1[1000+i-len1]=a[i]-'0';
	}
	for(int i=0;i<len3;i++)
	{
		arr3[1000+i-len3]=b[i]-'0';
	}
	int n=0;
	for(int j=999;j>=999-len3+1;j--)
	{
		for(i=999;i>=999-len1+1;i--)
		{
			res[i-n]+=arr1[i]*arr3[j];
			if(res[i-n]>=10)
			{
				res[i-1-n]+=res[i-n]/10;
				res[i-n]%=10;
			}
		}
		n++;
	}
	for(i=0;i<1000;i++)
	{
		if(res[i]!=0)
		break;
	}
	if(i==1000)
	{
		c[0]='0';
	}
	else
	{
		for(int j=i;j<=999;j++)
			c[j-i]=res[j]+'0';
	}
}
