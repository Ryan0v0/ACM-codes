//
// Created by 赵婉如 on 2019-09-24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int col[10];
int n,m,ans = 0;
bool used[10][10];
bool ue[100];
int x[100],y[100];
void match()
{
    memset(used,0,sizeof(used));
    /*for(int i = 0;i<10;i++)
     for(int j = 0;j<10;j++)
     {
      if(i<=j)
       used[i][j] = false;
      else used[i][j] = true;
     }*/
    int tmp = 0;
    for(int i = 1;i<= m;i++)
    {
        int tx = col[x[i]],ty = col[y[i]];
        if(tx>ty)swap(tx,ty);
        if(!used[tx][ty])
        {
            used[tx][ty]=true;
            tmp++;
        }
    }
    ans = max(ans,tmp);
}
void dfs(int dep)
{
    if(dep>n)
    {
        match();
        return ;
    }
    for(int i = 1;i<= 6;i++)
    {
        col[dep] = i;
        dfs(dep+1);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i<= m;i++)
        scanf("%d%d",&x[i],&y[i]);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}