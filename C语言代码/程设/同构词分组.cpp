#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(char *)a-*(char *)b;
}
int main()
{
	int n,vis[60];
	char arr[60][20];
	char res[60][60];
	memset(vis,0,sizeof(vis));
	memset(arr,0,sizeof(arr));
	memset(res,0,sizeof(res));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",arr[i]);
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(arr[i],arr[j])>0)
			{
				char temp[20];
				memset(temp,0,sizeof(temp));
				strcpy(temp,arr[i]);
				memset(arr[i],0,sizeof(arr[i]));
				strcpy(arr[i],arr[j]);
				memset(arr[j],0,sizeof(arr[j]));
				strcpy(arr[j],temp);
			}
		}
	int x=0,y=0;
 	for(int i=0;i<n;i++)
	{
		y=0;
		char cop1[20],cop2[20];
		if(vis[i]==0)
		{
			res[x][y++]=i+'0';
			vis[i]=1;
		}
		else if(vis[i]!=0)
			continue;
		for(int j=0;j<n;j++)
		{
			if(vis[j]!=0)
				continue;
			int lim1,lim2;
			memset(cop1,0,sizeof(cop1));
			memset(cop2,0,sizeof(cop2));
			strcpy(cop2,arr[i]);
			strcpy(cop1,arr[j]);
			lim1=strlen(arr[j]);
			lim2=strlen(arr[i]);
			qsort(cop1,lim1,sizeof(cop1[0]),cmp);
			qsort(cop2,lim2,sizeof(cop2[0]),cmp);
			if(strcmp(cop2,cop1)==0&&vis[j]==0)
			{
				res[x][y++]=j+'0';
				vis[j]=1;
			}
		}
		x++;
	}
	for(int i=0;i<x;i++)
	{
		int len1=strlen(res[i]);
		for(int j=0;j<len1;j++)
		{
			if(j==0)
			{
				printf("%s",arr[res[i][j]-'0']);
			}
			else
				printf(" %s",arr[res[i][j]-'0']);
		}
		printf("\n");
	}
	return 0;
}
