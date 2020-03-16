//
// Created by 赵婉如 on 2019-08-31.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 10000000000000000////
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0LL, f = 1LL;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1LL;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10LL * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}
const int N=4e5+10;
int tot=0,head[N];
struct edge{int go,next;}e[N];
struct node{LL l,r;}a[N];
void add(int x,int y)
{
    e[++tot]=(edge){y,head[x]};head[x]=tot;
    e[++tot]=(edge){x,head[y]};head[y]=tot;
}
int n;
int t[N][5];
int mn[N];
int id[N];
int tot=0;
void dfs(int x)
{
    if(x==0) return;
    id[x]=++tot;
    dfs(t[x][0]);
    mn[x]=min(mn[x],mn[t[x][0]]);
    dfs(t[x][1]);
    mn[x]=min(mn[x],mn[t[x][1]]);
    if(mn[t[x][0]]<mn[t[x][1]]){

    }

}
int main()
{
    int tt=read();
    while(tt--){
        n=read();tot=0;
        F(i,1,n){
            //int x=read();int y=read();
            t[i][0]=read();
            t[i][1]=read();
        }
    }
    return 0;
}