#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int mat[8][8];
int ans = 0;
bool check(int row,int col)
{
    for(int i=0;i<row;i++)
    {
        //不能同列
        if(mat[i][col])
        {
            return false;
        }
        //不能在同一对角线
        for(int j=0;j<8;j++)
        {
            if(mat[i][j])
            {
                if( fabs(i - row) - fabs(j - col) == 0)
                {
                    return 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return true;
}

int dfs(int row)
{
    if(row>=8)
    {
        ans++;
    }

    for(int col=0;col<8;col++)
    {
        if(check(row,col))
        {
            mat[row][col] = 1;
            dfs(row + 1);
            mat[row][col] = 0;
        }
    }
}
int main()
{
    memset(mat,0,sizeof(mat));

    dfs(0);

    printf("total = %d\n",ans);
    return 0;
}

