#include<iostream>
#include<stdlib.h>
using namespace std;
int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}
int main(void)
{
	int n;
	while(cin>>n)
	{
		__int64 * w=new __int64[n+1];  //ÿ��ľ��ļ�ֵ

		for(int p=1;p<=n;p++)
			scanf("%I64d",&w[p]);

		qsort(w,n+1,sizeof(__int64),cmp);

		__int64 mincost=0;
		for(int i=1;i<=n-1;i++)  //ÿ��ö���������е�ǰ2������С����Ԫ�أ���i��n-1����
		{
			__int64 sum=w[i]+w[i+1];   //��ʱw[i]��w[i+1]�Ѿ�û������
			mincost+=sum;

			for(int j=i+2;j<=n;j++)  //Ѱ��w[i]+w[i+1]��sum���������еĺ���λ�ã�������
			{
				if(sum>w[j])   //sum���ڵ�ǰԪ��
				{
					w[j-1]=w[j];  //��ǰԪ��ǰ��һ��
					if(j==n)   //sum��������Ԫ��(����������Ԫ��)
					{
						w[j]=sum; //���뵽���
						break;
					}
				}
				else
				{
					w[j-1]=sum;  //���뵽��sum��ĵ�һ��Ԫ��ǰ��(��ǰ��Ԫ�ؾ���ǰ��)
					break;
				}
			}
		}
		printf("%I64d\n",mincost);
	}
	return 0;
}
