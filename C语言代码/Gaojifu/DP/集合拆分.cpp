/*
*	DP[i]��ʾ���i�ĺ͵�����
*	״̬ת�Ʒ���ΪDP[i]+=DP[i-j]
*	��ʼ������DP[0]=1 
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
long long dp[39];
int main()
{
	int n;
	int target;
	scanf("%d",&n);
	if((n+1)*n%4!=0)
	{
		printf("0\n");
		return 0;
	}
	dp[0]=1;
	target=(n+1)*n/4;
	for(int i=1;i<=n;i++)
	{
		for(int j=target;j>=i;j--)
		{
			dp[j]+=dp[j-i];
		}
	}
	printf("%d\n",dp[target]/2);
	return 0;
}
