#include<stdio.h>
#include<string.h>
#include<ctype.h>
char list[10010][81];
char c;
char danci[81];
int x=0,y=0;
void juge()
{
	int j,i;
	if(y==0)
		return ;
	for(i=1;i<=x;i++)
	{
		
		for(j=0;j<=y;j++)
		{
			if(danci[j]!=list[i][j])
				break;
		}
		if(j==y+1)
		{
			printf("%d",i);
			return ;
		}
	}
	strcpy(list[++x],danci);
		printf("%s",danci);
}
int main()
{
	memset(list,'\0',sizeof(list));
	while((c=getchar())!=EOF)
	{
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')
			danci[y++]=c;
		if(!isalpha(c))
		{
			danci[y]='\0';
			juge();
			printf("%c",c);
			y=0;
		}
	}
	return 0;
}
