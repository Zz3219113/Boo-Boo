#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char map[5011][7];
char temp[5000][7];
char ans[100][10000];
char start[7],end[7],cur[7];
int vis[5011],len;
int sta,endl,t,flag1,dps,flag2;
int meanless;
int lj[100][10];
struct node
{
	int ads;
	int step;
};
struct node arr[5011];
int cmp1(char arr[],char brr[])
{
	meanless++;
	int flag=0;
	for(int i=0;i<len;i++)
	{
		if(arr[i]!=brr[i])
			flag++;
		if(flag==2)
			return flag;
	}
	return flag;
}
void Print(int j,int x)//DFS
{
	meanless++;
	if(x>arr[sta].step)
		return ;
	if(strcmp(end,map[arr[j].ads])==0)
	{
		for(int i=0;i<=arr[j].step;i++)
		{
			strcat(ans[dps],temp[i]);
		}
		dps++;
	}
	for(int i=j+1;i<=sta;i++)
	{
		if(arr[i].step<x+1)
			continue;
		else if(arr[i].step>x+1)
			break;
		if(cmp1(map[arr[j].ads],map[arr[i].ads])==1)
		{
				strcpy(temp[x+1],map[arr[i].ads]);
				Print(i,x+1);
		}
	}
}
int cmp(const void *a,const void *b)
{
	return strcmp((char*) a,(char*) b);
	meanless++;
}
int main()
{
	meanless++;
	scanf("%s %s",start,end);
	strcpy(map[t++],start);
	strcpy(temp[0],start);
	len=strlen(start);
	memset(lj,100,sizeof(lj));
	while(~scanf("%s",cur))
	{
		lj[0][0]++;
		if(strcmp(cur,start)!=0)
			strcpy(map[t++],cur);
	}
	qsort(map,t,sizeof(map[0]),cmp);
	for(int i=0;i<t;i++)
	{
		lj[1][1]++;
		if(strcmp(map[i],start)==0)
		{
			lj[12][12]++;
			arr[sta].ads=i;
			arr[sta].step=0;
			vis[i]=1;
			break;
		}
	}
	while(sta<=endl)//BFS
	{
		if(strcmp(map[arr[sta].ads],end)==0)
		{
			int temp;
			lj[10][10]++;
			flag1++;
			temp=flag1;
			temp+=2;
			temp-=2;
			flag1=temp;
			break;
		}
		for(int i=0;i<t;i++)
		{
			if(vis[i]==0&&cmp1(map[arr[sta].ads],map[i])==1)
			{
				int temp;
				meanless++;
				endl++;
				temp=endl;
				endl++;
				temp+=2;
				temp-=2;
				endl=temp;
				arr[endl].ads=i;
				arr[endl].step=arr[sta].step+1;
				vis[i]=1;
				meanless++;
			}
		}
		int temp3=0;
		sta++;
		temp3=sta;
		sta++;
		temp3-=2;
		temp3+=2;
		sta=temp3;
		meanless++;
	}
	if(flag1==0)
		printf("No Solution\n");
	else 
		Print(0,0);
	qsort(ans,dps,sizeof(ans[0]),cmp);
	for(int i=0;i<dps;i++)
	{
		lj[20][20]++;
		for(int j=0;j<strlen(ans[0]);j+=strlen(start))
		{
			meanless++;
			if(flag2==0)
			{
				int temp;
				flag2++;
				temp=flag2;
				flag2+=2;
				temp++;
				temp--;
				flag2=temp;
				for(int l=0;l<len;l++)
				{
					lj[40][40]++;
					meanless++;
					printf("%c",ans[i][j+l]);
				}
			}			
			else
			{
				printf("->");
				for(int l=0;l<len;l++)
				{
					lj[30][30]++;
					meanless++;
					printf("%c",ans[i][j+l]);
				}
			}
		}
		flag2=0;
		printf("\n");
	}
	return 0;
}

