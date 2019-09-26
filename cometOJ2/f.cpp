//
// Created by 赵婉如 on 2019-08-31.
//

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
#define int long long

const int N = 205;
const int M = 20005;

int d[N][N];
int f[N][N];
int a[N];
int n,m;

struct ques {
    int x,y,id;
    int w;
    int ans;
}q[M];

bool cmp_id(ques a,ques b) {
    return a.id<b.id;
}
bool cmp_w(ques a,ques b) {
    return a.w>b.w;
}

struct node {
    int x;
    int w;
}p[N];

bool cmp_node_w(node a,node b) {
    return a.w<b.w;
}

bool vis[N];

main() {
    int T,kcas=0;
    scanf("%lld",&T);
    while(T--) {
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
            p[i].w=a[i];
            p[i].x=i;
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                scanf("%lld",&d[i][j]);
                f[i][j]=d[i][j];
            }
        }

        for(int i=1;i<=m;i++) {
            scanf("%lld%lld%lld",&q[i].x,&q[i].y,&q[i].w);
            q[i].id=i;
        }

        sort(q+1,q+m+1,cmp_w);
        sort(p+1,p+n+1,cmp_node_w);

        int l=1;
        for(int o=m;o>=1;o--) {
            while(l <= n && p[l].w<=q[o].w) {
                int k=p[l].x;
                vis[k]=1;
                for(int i=1;i<=n;i++) {
                    for(int j=1;j<=n;j++) {
                        if(f[i][k]+f[k][j]<f[i][j]) {
                            f[i][j]=f[i][k]+f[k][j];
                        }
                    }
                }
                l++;
            }

            q[o].ans=f[q[o].x][q[o].y];
        }
        sort(q+1,q+m+1,cmp_id);
        printf("Case #%lld:\n",++kcas);
        for(int i=1;i<=m;i++) {
            printf("%lld\n",q[i].ans);
        }
    }
    return 0;
}