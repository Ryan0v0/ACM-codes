//
// Created by 赵婉如 on 2019-08-20.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 50005;

int n , pre[N] , mcnt;
int val[N] , filp[N] , state;
int X , Y , f[N][2];
struct edge
{
    int x , next;
}e[N];

void dfs(int x)
{
    if (filp[x]) state ^= 1;
    if (state) val[x] = -val[x];
    f[x][0] = val[x] , f[x][1] = -val[x];
    for (int i = pre[x] ; ~i ; i = e[i].next)
    {
        int y = e[i].x;
        dfs(y);
        f[x][0] += max(f[y][0] , f[y][1] - (filp[y] ? Y : X));
        f[x][1] += max(f[y][1] , f[y][0] - (filp[y] ? Y : X));
    }
    if (filp[x]) state ^= 1;
    printf("dp[%d][0]=%d,dp[%d][1]=%d\n",x,f[x][0],x,f[x][1]);
}

void work()
{
    int i , x , y;
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= n ; ++ i)
    {
        scanf("%d%d%d%d",&val[i] , &x , &filp[i] , &y);
        if (y) val[i] = -val[i];
        e[mcnt] = (edge){i , pre[x]} , pre[x] = mcnt ++;
    }

    dfs(0);
    if (f[0][0] < 0)
        puts("HAHAHAOMG");
    else
        printf("%d\n" , f[0][0]);
}

int main()
{
    while (~scanf("%d%d%d",&n,&X,&Y))
        work();
    return 0;
}
