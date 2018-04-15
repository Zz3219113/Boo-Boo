#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n,i,length,j,t;
	char a[10000];
	scanf("%d",&t);
	getchar();
	for(i=1;i<=t;i++)
	{	memset(a,0,sizeof(a));
		gets(a);
		n=strlen(a);
		if(a[n-4]=='d'&&a[n-3]=='e'&&a[n-2]=='s'&&a[n-1]=='u')
		{
			a[n-4]='n';
			a[n-3]='a';
			a[n-2]='n';
			a[n-1]='o';
			printf("Case #%d: %sdesu\n",i,a);
		}
		else
			printf("Case #%d: %snanodesu\n",i,a);
	}
	return 0;
}

