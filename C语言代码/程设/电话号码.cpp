#include<stdio.h>
#include<string.h>
#include<math.h>
int arr[1550][2],res=0;
unsigned int bitmap[62600];
char input[30],c;
void juge(int x,int y)
{
	if(y==3)
	{
		int dex=(x-3000000)/32;
		int ads=(x-3000000)%32;
		if(((bitmap[dex]>>(ads))&1)==0)
			bitmap[dex]+=pow(2,ads);
		else
		{
			int i;
			for(i=0;i<res;i++)
			{
				if(x==arr[i][0])
				{
					arr[i][1]++;
					break;
				}
			}
			if(i==res)
			{
				arr[res][0]=x;
				arr[res][1]++;
				res++;
			}
		}
	}
	else if(y==6)
	{
		int dex=(x-5000000)/32;
		int ads=(x-5000000)%32;
		if(((bitmap[dex]>>(ads))&1)==0)
		{
			//printf("%d %d %d\n",bitmap[dex],bitmap[dex]>>(ads),(bitmap[dex]>>(ads))%2);
			bitmap[dex]+=pow(2,ads);
		}	
		else
		{
			int i;
			for(i=0;i<res;i++)
			{
				if(x==arr[i][0])
				{
					arr[i][1]++;
					break;
				}
			}
			if(i==res)
			{
				arr[res][0]=x;
				arr[res][1]++;
				res++;
			}
		}
	}
}
int main()
{
	int flag1=0,flag2=0,inx=0,turn=0;
	printf("Error:\n");
	while((c=getchar())!=EOF)
	{
		if(c!='\n')
			input[inx++]=c;
		else
		{
			input[inx]='\0';
			inx=0;
			int len=strlen(input);
			turn=0;
			for(int i=0;i<len;i++)//turn -> num 
			{
				if(input[i]=='-')
					continue;
				else if(input[i]>='0'&&input[i]<='9')
					turn=turn*10+input[i]-'0';
				else if(input[i]>='A'&&input[i]<='Z')
				{
					if(input[i]>='A'&&input[i]<='C')
						turn=turn*10+2;
					else if(input[i]>='D'&&input[i]<='F')
						turn=turn*10+3;
					else if(input[i]>='G'&&input[i]<='I')
						turn=turn*10+4;
					else if(input[i]>='J'&&input[i]<='L')
						turn=turn*10+5;
					else if(input[i]>='M'&&input[i]<='O')
						turn=turn*10+6;
					else if((input[i]=='P')||(input[i]=='R')||(input[i]=='S'))
						turn=turn*10+7;
					else if(input[i]>='T'&&input[i]<='V')
						turn=turn*10+8;
					else if(input[i]>='W'&&input[i]<='Y')
						turn=turn*10+9;
					else
						flag1++;
				}
				else 
					continue;
			}
			if(flag1!=0)
			{
				flag2++;
				printf("%s\n",input);
				flag1=0;
			}
			else
			{
				if(turn/1000000==3||turn/1000000==6)
				{
					juge(turn,turn/1000000);
				}
				else
				{
					flag2++;
					printf("%s\n",input);
				}
			}	
		}
	}
	if(flag2==0)
		printf("Not found.\n");
	flag2=0;
	printf("\nDuplication:\n");
	if(res==0)
	{
		printf("Not found.\n");
		return 0;
	}
	for(int i=0;i<res;i++)
		for(int j=i;j<res;j++)
			if(arr[i][0]>arr[j][0])
			{
				int temp1,temp2;
				temp1=arr[i][0];
				arr[i][0]=arr[j][0];
				arr[j][0]=temp1;
				temp2=arr[i][1];
				arr[i][1]=arr[j][1];
				arr[j][1]=temp2;
			}
	for(int i=0;i<res;i++)
		printf("%d-%04d %d\n",arr[i][0]/10000,arr[i][0]%10000,arr[i][1]+1);
	return 0;
}
