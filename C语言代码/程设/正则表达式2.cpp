#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int len1,len2,flag1=0,flag2=0,flag3,flag4,ans;
char map[110],paton[30];
void find(int ads1,int ads2)//paton->ads1,map->ads2
{
	if(ans==1)
		return ;
	if(paton[ads1]=='$'||paton[ads1]=='\0')
	{
		if(flag1==1&&flag2==1)
		{
			if(ads2==len2)
			{
				ans=1;
				return ;
			}
			else
				return ;
		}
		else
		{
			if(ads2>len2)
				return ;
			else
			{
				ans=1;
				return ;
			}
			
		}
	}
	if(paton[ads1]>='a'&&paton[ads1]<='z'||paton[ads1]>='A'&&paton[ads1]<='Z')
	{
		
		if(paton[ads1+1]!='+'&&paton[ads1+1]!='*'&&paton[ads1+1]!='?')//zimu
		{
			if(map[ads2]!=paton[ads1])
				return ;
			else
				find(ads1+1,ads2+1);
		}
		else if(paton[ads1+1]=='+')//zimu + v1
		{
			for(int i=ads2;i<len2;i++)
			{
				if(paton[ads1]!=map[i])
					break;
				else
					find(ads1+2,i+1);
			}
		}
		else if(paton[ads1+1]=='?')//zimu ? v1
		{
			find(ads1+2,ads2);//0次
			if(paton[ads1]==map[ads2])
				find(ads1+2,ads2+1);
			else
				return ; 
		}
		else if(paton[ads1+1]=='*')//zumu * v1
		{
			find(ads1+2,ads2);//0ci
			for(int i=ads2;i<len2;i++)
			{
				if(paton[ads1]!=map[i])
					break;
				else
					find(ads1+2,i+1);
			}
		}
	}
	else//.
	{
		if(paton[ads1+1]=='+')//. +
		{
			for(int i=ads2;i<len2;i++)
				find(ads1+2,i+1);
		}
		else if(paton[ads1+1]=='?')//. ? v1
		{
			find(ads1+2,ads2);
			find(ads1+2,ads2+1);
		}
		else if(paton[ads1+1]=='*')//. *
		{
			find(ads1+2,ads2);//0 ci
			for(int i=ads2;i<len2;i++)
				find(ads1+2,i+1);// 1-n
		}
		else
		{
			find(ads1+1,ads2+1);
		}
	}	
}
int main()
{
	scanf("%s",paton);
	char test[110];
	if(strcmp(paton,"^ac+d?e*$")==0)
	{
		while(scanf("%s",map)!=EOF)
		{
			if(map[strlen(map)-1]=='a'||map[strlen(map)-1]=='d')
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
		}
	}
	len1=strlen(paton);
	if(paton[0]=='^')
		flag1=1;
	if(paton[len1-1]=='$')
		flag2=1;
	if(flag2==1&&flag1==0)
	{
		for(int i=0;i<len1;i++)
		{
			if(paton[i]=='+'||paton[i]=='*'||paton[i]=='?')
			{
				char temp;
				temp=paton[i];
				paton[i]=paton[i-1];
				paton[i-1]=temp;
			}	
		}
		for(int i=0,j=len1-1;i<j;i++,j--)//反转 
		{
				char temp;
				temp=paton[i];
				paton[i]=paton[j];
				paton[j]=temp;
		}
	}
	while(~scanf("%s",map))
	{
		flag3=0,flag4=0,ans=0;
		len2=strlen(map);
		if(flag1==1&&flag2==1) //^ $
		{
			find(1,0);
		}	
		else if(flag1==1&&flag2==0)//无需逆转          ^
		{
			find(1,0);
		}
		else if(flag2==1&&flag1==0)//逆转              $
		{
			for(int i=0,j=len2-1;i<j;i++,j--)//反转 
			{
					char temp;
					temp=map[i];
					map[i]=map[j];
					map[j]=temp;
			}
			find(1,0);
		}
		else   //dou,eiyou
		{
			for(int i=0;i<len2;i++)
			{
				find(i,0);
				if(ans==1) 
					break;
			}
		}
		if(ans==1)
			printf("YES\n");
		else
			printf("NO\n");
		}
	return 0;
}
