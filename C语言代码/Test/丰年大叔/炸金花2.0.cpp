#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	char A[3][10],B[3][10],temp[10]={0};
	int i,Ta[3][4],Tb[3][4],flag=1,temp1,temp2,j,juge1=0,value1=0,value2=0,poker1[20],poker2[20];
	memset(poker1,0,sizeof(poker1));
	memset(poker2,0,sizeof(poker2));
	memset(Ta,0,sizeof(Ta));
	memset(Tb,0,sizeof(Tb)); 
	for(i=0;i<3;i++)
		scanf("%s",A[i]);
	for(i=0;i<3;i++)
		scanf("%s",B[i]);
	if(strcmp(A[0],A[1])==0||strcmp(A[1],A[2])==0||strcmp(A[0],A[2])==0)
		flag=0;
	if(strcmp(B[0],B[1])==0||strcmp(B[2],B[1])==0||strcmp(B[0],B[2])==0)
		flag=0;
	for(i=0;i<3;i++)
	{
		switch(A[i][0])
		{
			case 72:{Ta[i][0]=4;break;}
			case 83:{Ta[i][0]=3;break;}
			case 68:{Ta[i][0]=2;break;}
			case 67:{Ta[i][0]=1;break;}
		}
		if(A[i][2]=='\0')
		{
			if(A[i][1]>='2'&&A[i][1]<='9')
				Ta[i][1]=A[i][1]-'0';
			else if(A[i][1]=='J')
				Ta[i][1]=11;
			else if(A[i][1]=='Q')
				Ta[i][1]=12;
			else if(A[i][1]=='K')
				Ta[i][1]=13;
			else if(A[i][1]=='A')
				Ta[i][1]=14;		
			else
				flag=0;
		}
		else if(A[i][2]=='0'&&A[i][1]=='1'&&A[i][3]=='\0')
			Ta[i][1]=10;
		else
			flag=0;
		poker1[Ta[i][1]]++;	
	}
	for(i=0;i<3;i++)
	{
		switch(B[i][0])
		{
			case 72:{Tb[i][0]=4;break;}
			case 83:{Tb[i][0]=3;break;}
			case 68:{Tb[i][0]=2;break;}
			case 67:{Tb[i][0]=1;break;}
		}
			if(B[i][2]=='\0')
		{
			if(B[i][1]>='2'&&B[i][1]<='9')
				Tb[i][1]=B[i][1]-'0';
			else if(B[i][1]=='J')
				Tb[i][1]=11;
			else if(B[i][1]=='Q')
				Tb[i][1]=12;
			else if(B[i][1]=='K')
				Tb[i][1]=13;
			else if(B[i][1]=='A')
				Tb[i][1]=14;
			else
				flag=0;	
		}
		else if(B[i][2]=='0'&&B[i][1]=='1'&&B[i][3]=='\0')
			Tb[i][1]=10;
		else 
			flag=0;	
		poker2[Tb[i][1]]++;	
	}
	if(flag==0)
	{	
		printf("Input Error!\n");
		return 0;	
	}
	for(j=0;j<2;j++)//排序 
	{
		for(i=0;i<2-j;i++)
		{
			if((Ta[i][1]==Ta[i+1][1]&&Ta[i][0]<Ta[i+1][0])||Ta[i][1]<Ta[i+1][1])
			{
				temp1=Ta[i][0];
				Ta[i][0]=Ta[i+1][0];
				Ta[i+1][0]=temp1;
				temp2=Ta[i][1];
				Ta[i][1]=Ta[i+1][1];
				Ta[i+1][1]=temp2;
				strcpy(temp,A[i]);
				memset(A[i],0,sizeof(A[i]));
				strcpy(A[i],A[i+1]);
				memset(A[i+1],0,sizeof(A[i+1]));
				strcpy(A[i+1],temp);
			}
		}
	}
	for(j=0;j<2;j++)//排序 
	{
		for(i=0;i<2-j;i++)
		{
			if((Tb[i][1]==Tb[i+1][1]&&Tb[i][0]<Tb[i+1][0])||Tb[i][1]<Tb[i+1][1])
			{
				temp1=Tb[i][0];
				Tb[i][0]=Tb[i+1][0];
				Tb[i+1][0]=temp1;
				temp2=Tb[i][1];
				Tb[i][1]=Tb[i+1][1];
				Tb[i+1][1]=temp2;
				memset(temp,0,sizeof(temp));
				strcpy(temp,B[i]);
				memset(B[i],0,sizeof(B[i]));
				strcpy(B[i],B[i+1]);
				memset(B[i+1],0,sizeof(B[i+1]));
				strcpy(B[i+1],temp);
			}
		}
	}
	if(Ta[0][1]-1==Ta[1][1]&&Ta[1][1]-1==Ta[2][1])	
	{
		if(Ta[0][0]==Ta[1][0]&&Ta[2][0]==Ta[0][0]) 
			value1=200+Ta[0][1];//同花顺
		else
			value1=100+Ta[0][1];//顺子
	}
	if(Tb[0][1]-1==Tb[1][1]&&Tb[1][1]-1==Tb[2][1])
	{
		if(Tb[0][0]==Tb[1][0]&&Tb[2][0]==Tb[0][0])
			value2=200+Tb[0][1];//同花顺
		else
			value2=100+Tb[0][1];//顺子
	}
	for(i=1;i<15;i++)
	{
		if(poker1[i]==3)//炸弹 
			value1=150+i;
		if(poker2[i]==3)//炸弹
			value2=150+i;
		if(poker1[i]==2)//对子 
			value1=50+i;
		if(poker2[i]==2)//对子 
			value2=50+i;
	}
	if(value1>value2)
	{
		juge1=-1;
		goto OP;
	}
	if(value1<value2)
	{
		juge1=1;
		goto OP;
	}
	else
	{
		i=0;j=0;
		while(i<=2||j<=2)
		{
			if(Ta[i][1]>Tb[j][1])
			{
				juge1=-1;
				goto OP;
			}
			else if(Ta[i][1]<Tb[j][1])
			{
				juge1=1;
				goto OP;
			}
			else if(Ta[i][1]==Tb[j][1])
			{
				if(Ta[i][0]>Tb[j][0])
				{
					juge1=-1;
					goto OP;
				}
				else if(Ta[i][0]<Tb[j][0])
				{
					juge1=1;
					goto OP;
				}
				else 
					i++;j++;
			}
		}
	}
	if(juge1==0)
		printf("Draw!\n");
	OP:switch(juge1)
	{
		case 1:printf("Winner is B!\n");break;
		case -1:printf("Winner is A!\n");break;
	}
	printf("A:"); 
	for(i=0;i<3;i++)
	{
		printf(" %s",A[i]);
	}
	printf("\n");
	printf("B:");
	for(i=0;i<3;i++)
	{
		printf(" %s",B[i]);
	}
	printf("\n");
 	return 0;
}

