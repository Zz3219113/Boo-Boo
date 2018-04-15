#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int cont1,cont2;
char str[100010];
char vis[100010];
void find(int x)
{
	
}
int main()
{
	int n;
	while(~scanf("%d",&n));
	for(int i=1;i<=n;i++)
	{
		int cont1=0,cont2=0,res=0;
		scanf("%c",&str[i]);
		if(str[i]=='w')
			cont1+;
		else if(str[i]=='b')
			cont2++;
		for(int i=1;i<n;i+=2)
		{
			if(vis[i]==1)
				continue;
			if(str[i]==str[i+1])
			{
				if(str[i]=='w')
					cont1-=2;
				else if(str[i]=='b')
					cont2-=2;
			}
			else
			{
				if(cont1%2==0)
				{
					int j;
					for(j=i+2;j<n;j++)
					{
						if(str[j]!=str[j+1])
						{
							vis[j]=1;
							break;
						}	
					}
				}
				else
				{
					res++;
					if(str[i]==w)
						cont1--;
					else
						cont2--;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
