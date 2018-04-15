#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int money;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&money);
		int ans=upper_bound(a,a+n,money)-a;
		printf("%d\n",ans);
	}
	return 0;
}
