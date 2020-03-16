//
// Created by 赵婉如 on 2019-08-22.
//

#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5+5;
const double eps = 1e-8;

struct node
{
    double p[2];
} a[maxn];

int n;
double es;

double solve(int x,int &u,int &v)
{
    for(int i = 1;i<= n;i++) a[i].p[x]*= es;
    double dis[5][2];
    int ans[5][2];
    for(int i = 0;i< 5;i++) dis[i][0] = -1e15,dis[i][1] = 1e15;
    for(int i = 1;i<= n;i++)
    {
        for(int j = 0;j< 1<<2;j++)
        {
            double tmp = 0.0;
            for(int k = 0;k< 2;k++)
            {
                if(j&(1<<k)) tmp+= a[i].p[k];
                else tmp-= a[i].p[k];
            }

            if(tmp> dis[j][0])
            {
                dis[j][0] = tmp;
                ans[j][0] = i;
            }
            if(tmp< dis[j][1])
            {
                dis[j][1] = tmp;
                ans[j][1] = i;
            }
        }
    }

    double ma = 0.0;
    for(int j = 0;j< 1<<2;j++)
    {
        if(ma< dis[j][0]-dis[j][1])
        {
            ma = dis[j][0]-dis[j][1];
            u = ans[j][0];
            v = ans[j][1];
        }
    }
    for(int i = 1;i<= n;i++) a[i].p[x]/= es;
    return ma;
}

int main()
{
    cin>>n;
    for(int i = 1;i<= n;i++)
        scanf("%lf %lf",&a[i].p[0],&a[i].p[1]);

    es = sqrt(2.0)-1.0;

    int a1,a2,a3,a4;
    double ans1 = solve(0,a1,a2);
    double ans2 = solve(1,a3,a4);

    if(ans1> ans2) printf("%d %d\n",a1,a2);
    else printf("%d %d\n",a3,a4);

    return 0;
}