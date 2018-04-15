#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char arr[100010];
char brr[100010];
char crr[100010];
int n,cnt[30];
int juge(char x)
{
	for(int i=0;i<x-'a';i++)
	{
		if(cnt[i]!=0)
			return 1;
	}
	return 0;
}
int main()
{
	while(~scanf("%s",arr))
	{
		int res=0,ads=0;
		n=strlen(arr);
		for(int i=0;i<n;i++)
		{
			cnt[arr[i]-'a']++;
		}
		for(int i=0;i<n;i++)
		{
			brr[++res]=arr[i];
			cnt[arr[i]-'a']--;
			if(juge(arr[i]))
				continue;
			else
			{
				for(;res>=1;res--)
				{
					if(juge(brr[res]))
						break;
					else
					{
						crr[++ads]=brr[res];
					}
				}
			}
		}
		for(int i=1;i<=ads;i++)
			printf("%c",crr[i]);
		for(int i=res;i>=1;i--)
			printf("%c",brr[i]);
		printf("\n");
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}

