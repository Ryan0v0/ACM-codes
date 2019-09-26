//
// Created by 赵婉如 on 2019-08-17.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f[2005][5005];
struct Node
{ll w,h;}mb[5005];
bool cmp1(const Node &a,const Node &b)
{
    if(a.h==b.h)return a.w<b.w;
    else return a.h<b.h;
}
ll sumw[5005],sum;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1;i<= n;i++)
    {
        scanf("%lld%lld",&mb[i].w,&mb[i].h);
        sum+=mb[i].w*mb[i].h;
    }
    sort(mb+1,mb+n+1,cmp1);
    for(int i = n;i>= 1;i--)
        sumw[i] = sumw[i+1]+mb[i].w;
    int now = 1,pre = 0;
    f[pre][1] = sumw[1]*mb[1].h;
    for(int i = 2;i<= k;i++)
    {
        for(int j = i;j<= n;j++)
        {
            f[now][j] = 0;
            for(int o = i-1;o<j;o++)
                f[now][j] = max(f[now][j],f[pre][o]+(mb[j].h-mb[o].h)*sumw[j]);
        }
        swap(now,pre);
    }
    ll ans = 1e18;
    for(int i = k;i<= n;i++)
        ans = min(ans,sum-f[pre][i]);
    printf("%lld\n",ans);
    return 0;
}
