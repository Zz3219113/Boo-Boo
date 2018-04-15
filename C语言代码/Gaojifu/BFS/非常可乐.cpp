/*BFS����
Author: shaorui
���ӵ�ַ: http://acm.hdu.edu.cn/showproblem.php?pid=1495
˼·��Ԥ����m < n < s���Ժ������
��ʼ״̬��m,n���п������Ϊ0��s�������Ϊs;
Ȼ����������:
1, s �� m
2, s �� n
3, m �� n
4, m �� s
5, n �� m
6, n �� s
ֱ��n,s���еĿ����ܵȷ֣���ʱm�������Ϊ0��Ϊֹ�������ܵȷ֣������ NO
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h> 
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 101
bool visited[maxn][maxn];
int m,n,s,si,sj;
struct node
{
    int x,y,all,t;  //x,y,all�ֱ��ʾm,n,s���п��ֵ������t��ʾ���˶��ٴ�
};
void BFS()
{
    queue<node> que;
    memset(visited,false,sizeof(visited));
    node p,q;
    p.x = 0,p.y = 0,p.t = 0,p.all = s;
    que.push(p);
    visited[p.x][p.y] = true;
    while(!que.empty())
    {
        p = que.front();
        que.pop();
        if(p.y == p.all && p.y == s/2)             
        {
            printf("%d\n",p.t);
            return;
        }
        if(p.all+p.x > m)                               //s��m
        {
            q.x = m,q.y = p.y,q.all = p.all+p.x-m,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        else
        {
            q.x = p.all+p.x,q.y = p.y,q.all = 0,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        if(p.all+p.y > n)                                //s��n
        {
            q.x = p.x, q.y = n, q.all = p.all+p.y-n,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        else
        {
            q.x = p.x,q.y = p.all+p.y,q.all = 0,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        if(p.x+p.y > n)                                //m��n
        {
            q.x = p.x+p.y-n,q.y = n,q.all = p.all,q.t = p.t+1; 
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        else
        {
            q.x = 0,q.y = p.x+p.y,q.all = p.all,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        q.all = p.all+p.x,q.x = 0,q.y = p.y,q.t = p.t+1; //m��s
        if(!visited[q.x][q.y])
            que.push(q),visited[q.x][q.y] = true;  
        if(p.x+p.y > m)
        {
            q.y = p.y+p.x-m,q.x = m,q.all = p.all,q.t = p.t+1;//n��m
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        else
        {
            q.x = p.x+p.y,q.y = 0,q.all = p.all,q.t = p.t+1;
            if(!visited[q.x][q.y])
                que.push(q),visited[q.x][q.y] = true;
        }
        q.all = p.all+p.y,q.x = p.x,q.y = 0,q.t = p.t+1; //n��s
        if(!visited[q.x][q.y])
            que.push(q),visited[q.x][q.y] = true;
    }
    printf("NO\n");
}
int main()
{
    //freopen("1013.txt","r",stdin);
    while(scanf("%d%d%d",&s,&m,&n) && (s||m||n))
    {
        if(s%2)
        {
            printf("NO\n");
            continue;
        }
        if(m > n) swap(m,n);
        BFS();
    }
    return 0;
}
