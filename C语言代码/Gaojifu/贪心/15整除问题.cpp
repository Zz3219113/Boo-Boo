/*
*						̰		��
*	�ܱ�ʮ����������λ����5����0 �Ҹ�λ֮��Ϊ3�ı��� 
*	�ڱ�֤�ܱ�3�����Ļ��������ֵ�λ�������ܶ� ɾȥ��С�����ٵ����� ʹ�ú�Ϊ3�ı���
*	���Խ����ְ����������� ������֮��Ϊ������Ϊ����ɾ����������
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
char arr[1010];
int sub[10],cont,flag;
void Del(int x)
{
	for(int i=0;i<9;i++)
	{
		if(i%3==x&&sub[i]>0)
		{
			sub[i]--;
			return ;
		}
	}
	flag=1;
}
int main()
{
	int sum,len,havezero;
	while(~scanf("%s",arr))
	{
		cont=0;
		flag=0;
		memset(sub,0,sizeof(sub));
		sum=0;
		len=strlen(arr);
		int temp;
		for(int i=0;i<len;i++)
		{
			temp=arr[i]-'0';
			sum+=temp;
			sub[temp]++;
		}
		if(sub[0]==0&&sub[5]==0)//���ܱ�5���� 
		{
			printf("impossible\n");
			continue;		
		}
		else
		{
			if(sub[0]==0&&sub[5]>0)//������β����
			{
				temp=5;
				sub[5]--;
			}
			else
			{
				temp=0;
				sub[0]--;
			}
		}
		if(sum%3==1)//Del mod=1 || Del mod=2*2
		{
			if(sub[1]+sub[4]+sub[7]>=1)
			{
				Del(1);	
			}
			else
			{
				Del(2);
				Del(2);
			}
		}
		else if(sum%3==2)//Del mod=2 || Del mod=1* 2
		{
			if(sub[2]+sub[5]+sub[8]>=1)
			{
				Del(2);
			}
			else
			{
				Del(1);
				Del(1);
			}
		}
		if(flag==0)
		{
			for(int i=9;i>=0;i--)
			{
				while(sub[i]>0)
				{
					if(i>0)
						cont++;
					if(i==0&&cont==0)
						break;
					printf("%d",i);
					sub[i]--;
				}
			}
			printf("%d\n",temp);
		}
		else
			printf("impossible\n");
	}
	return 0;
}
