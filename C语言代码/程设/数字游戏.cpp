#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int arr[110][110];
int cmp(const void *a,const void *b)
{
	char s1[12],s2[12];
	strcpy(s1,(char*) a);
	strcat(s1,(char*) b);
	strcpy(s2,(char*) b);
	strcat(s2,(char*) a);
	return strcmp(s2,s1);
}
int main()
{
	int t,n;
	memset(arr,0,sizeof(arr));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",&arr[i]);
		}
		qsort(arr,n,sizeof(arr[0]),cmp);
		if(arr[0][0]=='0')
		{
			printf("0\n");
			continue;
		}
		for(int i=0;i<n;i++)
			printf("%s",arr[i]);
		printf("\n");
	}
	return 0;
}

