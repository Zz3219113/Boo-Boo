#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
using namespace std;
struct node{  
    long long value;  
    bool operator < (const node &a) const {  
        return value>a.value;//最小值优先  
    }  
};
int main()
{
	node temp;
	long long res=0;
	long long sum=0;
	long long t;
	priority_queue<node>q;
	scanf("%lld",&t);
	long long flag=t;
	long long coast=0;
	while(flag--)
	{
		scanf("%lld",&temp.value);
		sum+=temp.value;
		q.push(temp);
	}
	while(!q.empty())
	{
		node ep1;
		node ep2;
		ep1=q.top();
		q.pop();
		ep2=q.top();
		q.pop();
		node count;
		count.value=ep1.value+ep2.value;
		res+=ep1.value+ep2.value;
		q.push(count);
		if(count.value==sum)
			break;
	}
	printf("%lld\n",res);
	return 0;
}
