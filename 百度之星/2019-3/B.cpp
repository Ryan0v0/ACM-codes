//
// Created by 赵婉如 on 2019-08-24.
//
#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define mo 998244353
using namespace std;
typedef long long LL;
using namespace std;
using LL=long long;

struct edge
{
    int v,next;
    LL c;
}E[2*2005+5];
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
int en,n,m,u,v,first[1005+5];
pair<LL,int> ans[1005+5],w;
multimap<pair<LL,int>,int> M;

void Dij(int s)
{
    F(i,1,n) ans[i].first=1E18,ans[i].second=0;
    ans[s].first=0;
    ans[s].second=0;
    for(int i=first[s];i;i=E[i].next){
        ans[E[i].v].first=min(ans[E[i].v].first,E[i].c);
        ans[E[i].v].second=0;
        M.insert(make_pair(make_pair(ans[E[i].v].first,0),E[i].v));
    }
    while(!M.empty()){
        u=M.begin()->second,w=M.begin()->first;
        M.erase(M.begin());
        if(ans[u]<w) continue;
        for(int i=first[u];i;i=E[i].next){
            pair<LL,int> pp=make_pair(ans[u].first+E[i].c,max(ans[u].second,u));
            if(ans[v=E[i].v]>pp)
                M.insert(make_pair(ans[v]=pp,v));
        }
    }
}

int T;
LL res;

int main()
{
    int tt=read();
    while(tt--){
        n=read();m=read();
        for(int i=1;i<=n;i++)
            first[i]=0;
        res=en=0;
        for(int i=1,c;i<=m;i++){
            u=read();v=read();c=read();
            E[++en]=(edge){v,first[u],c};first[u]=en;
            E[++en]=(edge){u,first[v],c};first[v]=en;
        }
        F(i,1,n){
            Dij(i);
           F(j,1,n){
                //cout<<ans[j].first<<' ';
                if (i != j)
                    (res += ans[j].second) %= mo;
            }
            //cout<<endl;
        }/*
        F(i,1,n){
            Dij(i);
            F(j,1,n) cout<<ans[j].second<<' ';
            cout<<endl;
        }*/
        cout<<res<<endl;
    }
    return 0;
}