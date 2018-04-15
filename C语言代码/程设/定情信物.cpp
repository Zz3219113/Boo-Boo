#include<stdio.h>
#include<string.h>
int main()
{
	int len,maxnum=0,max=0;
	int vis[360];
	
	char word[360];
	scanf("%d",&len);
	scanf("%s",word);
	for(int i=0;i<len;i++)
	{
		memset(vis,0,sizeof(vis));
		int left,right,max=0,temp1,temp2;
		char c1,c2;
		left=i-1;
		right=i;
		if(left<0)
			left=len-1;
		temp1=left;
		temp2=right;
		c1=word[left];
		c2=word[i];
		if(c1=='w')
			for(int i=0;i<len;i++)
			{
				if(temp1<0)
					temp1=len-1;
				if(word[temp1]!='w')
				{
					c1=word[temp1];
					break;
				}
				else
					temp1--;
			}
		if(c2=='w')
			for(int i=0;i<len;i++)
			{
				if(temp2>=len)
					temp2=0;
				if(word[temp2]!='w')
				{
					c1=word[temp2];
					break;
				}
				else
					temp2++;
			}
		while(1)
		{
			if(left>=0)
			{
				if((word[left]==c1||word[left]=='w')&&vis[left]==0)
				{	
					max++;
					vis[left]=1;
					left--;
				}
				else
					break;
			}
			else
				left=len-1;
		}
		while(1)
		{
			if(right+1<=len)
			{
				if((word[right]==c2||word[right]=='w')&&vis[right]==0)
				{
					max++;
					vis[right]=1;
					right++;	
				}
				else
					break;
			}
			else
				right=0;
		}
		if(max>maxnum)
			maxnum=max;
	}
	printf("%d\n",maxnum);
	return 0;
}
