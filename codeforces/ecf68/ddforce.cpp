//
// Created by 赵婉如 on 2019-09-27.
//
#include<bits/stdc++.h>
using namespace std;
int a[10], d[40][3], vis[12], ans;
void init()
{
    int cnt = 0;
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j +i <= 9; j++)
        {
            d[cnt][0] = i;
            d[cnt][1] = j;
            d[cnt++][2] = i+j;
            vis[i]++;vis[j]++;vis[i+j]++;
        }
}
bool check(int x)
{
    if(a[d[x][0]] < 0 || a[d[x][1]] < 0 || a[d[x][2]] < 0) return false;
    return true;
}
void add(int x, int val)
{
    a[d[x][0]] += val;
    a[d[x][1]] += val;
    a[d[x][2]] += val;
}
void dfs(int deep, int cnt)
{
    if(36 - deep + cnt <= ans || deep == 36) return ;
    add(deep, -1);
    if(check(deep))
    {
        ans = max(ans, cnt+1);
        dfs(deep+1, cnt+1);
    }
    add(deep, 1);
    dfs(deep+1, cnt);
}
int main()
{
    int t;
    init();
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++)
    {
        bool ok = true;
        for(int i = 1; i <= 9; i++)
        {
            scanf("%d", &a[i]);
            a[i] = min(a[i], 17 - i);
            if(a[i] < 17 - i) ok = false;
        }
        if(ok)
            printf("Case #%d: %d\n", kase, 36);
        else
        {
            ans = 0;
            dfs(0, 0);
            printf("Case #%d: %d\n", kase, ans);
        }
    }
    return 0;
}