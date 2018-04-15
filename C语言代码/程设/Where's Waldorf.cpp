#include<stdio.h>
#include<string.h>
int main()
{
	int t,m,n,times,len;
	char pass[60],input[50][50];
	scanf("%d",&t);
	while(t--)
	{
		memset(input,0,sizeof(input));
		scanf("%d %d",&m,&n);
		getchar();
		for(int k=0;k<m;k++)
		{
			scanf("%s",input[k]);
		}
		scanf("%d",&times);
		for(int i=0;i<times;i++)
		{
			scanf("%s",pass);
			len=strlen(pass);
		}
	}
	return 0;
}
