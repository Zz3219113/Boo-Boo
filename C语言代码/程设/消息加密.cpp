#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char input[110],ascll[130][3],turn[3],pre;
	int n,m;
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++)
	{
		scanf("%s %c",turn,&pre);
		strcpy(ascll[pre],turn);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",input);
		int len=strlen(input);
		for(int j=0;j<len;j++)
		{
			printf("%s",ascll[input[j]]);
		}
		printf("\n");
	}
	return 	0;
}
