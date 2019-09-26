//
// Created by 赵婉如 on 2019-08-31.
//

/* ***********************************************
Author        :BPM136
Created Time  :2018/7/17 21:39:31
File Name     :G.cpp
************************************************ */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

typedef long long ll;

const int N = 100005;
const int M = 105;
const ll inf = 1e17;

struct edge {
    int y,w,next;
}e[N<<1];
int last[N],ne;

ll f[N][M];
ll sum[N][M];
int siz[N];
int n,m;

void add(int x,int y,int w) {
    e[++ne].y=y; e[ne].w=w; e[ne].next=last[x]; last[x]=ne;
}
void add2(int x,int y,int w) {
    add(x,y,w);
    add(y,x,w);
}

ll cur[M];
ll sum_cur[M];
int du[N];
void dfs(int x,int pre) {
    siz[x]=0;
    f[x][0]=0; for(int i=1;i<=m;i++) f[x][i]=inf;
    sum[x][0]=0; for(int i=1;i<=m;i++) sum[x][i]=inf;
    int flag=1;
    for(int i=last[x];i!=0;i=e[i].next) {
        int y=e[i].y;
        if(y==pre) continue;
        flag=0;
        dfs(y,x);

        for(int p=0;p<=m;p++) cur[p]=f[x][p],f[x][p]=inf;
        for(int p=0;p<=m;p++) sum_cur[p]=sum[x][p],sum[x][p]=inf;
        int bound0=min(m,siz[x]);
        int bound1=min(m,siz[y]);
        for(int p=0;p<=bound0;p++) {
            for(int q=0;q<=bound1 && p+q<=m;q++) {
                if(f[x][p+q]>cur[p]+f[y][q]+(ll)e[i].w*(m-q)*q) {
                    f[x][p+q]=cur[p]+f[y][q]+(ll)e[i].w*(m-q)*q;
                }
            }
        }
        siz[x]+=siz[y];
    }
    if(siz[x]==0 && flag==1) {
        siz[x]=1;
        f[x][1]=0;
        sum[x][1]=0;
    }
}

int main() {
    int T,kcas=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        memset(last,0,sizeof(last));
        memset(du,0,sizeof(du));
        ne=0;
        int tmp;
        for(int i=1;i<n;i++) {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            tmp=w;
            add2(x,y,w);
            du[x]++; du[y]++;
        }
        if(n==2) {
            if(m==1) printf("Case #%d: 0\n",++kcas);
            if(m==2) printf("Case #%d: %d\n",++kcas,tmp);
            continue;
        }

        int root=0;
        for(int i=1;i<=n;i++) if(du[i]!=1) {
                root=i;
                break;
            }
        dfs(root,-1);
        printf("Case #%d: %lld\n",++kcas,f[root][m]);
    }
    return 0;
}