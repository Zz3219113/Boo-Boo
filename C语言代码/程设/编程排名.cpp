#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int num;//AC num
	int time;//Time
	int stu;//Student num
	int wacont[10000];//Wa
}arr[110];
/*int cmp(const void *a,const void *b)
{
	if((*(node*)a).num!=(*(node*)b).num)
		return (*(node*)b).num-(*(node*)a).num;
	else
	{
		if((*(node*)a).time!=(*(node*)b).time)
			return (*(node*)a).time-(*(node*)b).time;
		else
			return (*(node*)a).stu-(*(node*)b).stu;
	}
}*/  //À¬»ø±àÒëÆ÷  »ÙÎÒÇà´º 
int main()
{
	int n,t=1,m,stdnum,quenum,x=1;;
	char juge[4];
	while(~scanf("%d",&n),n)
	{
		
		memset(arr,0,sizeof(arr));
		while(~scanf("%d",&m))
		{
			if(m==0)
				break;
			scanf("%d%d%s",&stdnum,&quenum,juge);
			if(juge[0]=='y')
			{
				arr[stdnum].stu=stdnum;// Ñ§ºÅ 
				arr[stdnum].time+=m+arr[stdnum].wacont[quenum]*20;
				arr[stdnum].num++;
				arr[stdnum].wacont[quenum]=0;
			}
			else
			{
				arr[stdnum].stu=stdnum;
				arr[stdnum].wacont[quenum]++;
			}
		}
		printf("case %d:\n",x++);
		//qsort(arr+1,n,sizeof(arr[0]),cmp);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				int flag=0;
				if(arr[i].num<arr[j].num)
					flag=1;
				else if(arr[i].num==arr[j].num)
				{
					if(arr[i].time>arr[j].time)
						flag=1;
					else if(arr[i].time==arr[j].time)
						if(arr[i].stu>arr[j].stu)
							flag=1;		
				}
				if(flag==1)
				{
					int tem1,tem2,tem3;
					tem1=arr[i].num;
					arr[i].num=arr[j].num;
					arr[j].num=tem1;
					tem2=arr[i].time;
					arr[i].time=arr[j].time;
					arr[j].time=tem2;
					tem3=arr[i].stu;
					arr[i].stu=arr[j].stu;
					arr[j].stu=tem3;
				}
			}
		int perAC=0,perTime=0,t=0,cont1=0,cont2=0,count3=0;
		for(int i=1;i<=n;i++)
		{
			if(perAC==0&&perTime==0)
			{
				t++;
				printf("%d %d %d %d\n",arr[i].stu,arr[i].num,arr[i].time,t);
				perAC=arr[i].num;
				perTime=arr[i].time;
			}
			else
			{
				if(perAC==arr[i].num&&perTime==arr[i].time)
				{
					printf("%d %d %d %d\n",arr[i].stu,arr[i].num,arr[i].time,t);
					if(t==1)
						cont1++;
					if(t==2)
						cont2++;
				}
				else
				{
					if(cont1>=2&&t==1||cont2>=1&&t==2)
						break;
					else if(cont1==1&&t==1)
						t+=2;
					else
						t++;
					if(t>=4)
						break;
					printf("%d %d %d %d\n",arr[i].stu,arr[i].num,arr[i].time,t);
					perAC=arr[i].num;
					perTime=arr[i].time;
				}
			}
		}
	}
	return 0;
}
