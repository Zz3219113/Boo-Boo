#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int input;
int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
void get()
{
	char c;
	input=0;
	while((c=getchar())!='\n')
		input=input*10+c-'0';
}
int main()
{
	int n,m,ads=0,temp,j;
	scanf("%d%d",&n,&m);
	int *arr;
	getchar();
	if(m>=500000)
	{
		arr=(int *)calloc(n,sizeof(int));
		for(int i=0;i<n;i++)
		{
			get();
			*(arr+i)=input;
		}		
		qsort(arr,n,sizeof(int),cmp);
	}
	else
	{
		arr=(int *)calloc(m,sizeof(int));
		for(int i=0;i<n;i++)
		{
			get();
			if(ads==0)
			{
				arr[0]=input;
				ads++;
			}
			else
			{
				for(j=ads-1;j>=0;j--)
				{
					if(arr[j]<input)
						arr[j+1]=arr[j];
					else
					{
						arr[j+1]=input;
						if(ads<=m)
							ads++;
						break;
					}
				}
				if(j==-1)
					arr[0]=input;
			}
		}
	}
	for(int i=0;i<m;i++)
		printf("%d\n",*(arr+i));
	return 0;
}
