//
// Created by 赵婉如 on 2019-08-24.
//

#include<cstdio>
#include<map>
#include<algorithm>
#define mo 998244353
using namespace std;
using LL=long long;

struct edge
{
    int v,next;
    LL c;
}E[2*2005+5];

int en,n,m,u,v,first[1005+5];
pair<LL,int> ans[1005+5],w;
multimap<pair<LL,int>,int> M;

void Dij(int s)
{
    for(int i=1;i<=n;i++)
        ans[i].first=1E18,ans[i].second=0;
    ans[s].first=0;
    ans[s].second=0;
    for(int i=first[s];i;i=E[i].next)
    {
        ans[E[i].v].first=min(ans[E[i].v].first,E[i].c);
        ans[E[i].v].second=0;
        M.insert(make_pair(make_pair(ans[E[i].v].first,0),E[i].v));
    }
    while(!M.empty())
    {
        u=M.begin()->second,w=M.begin()->first;
        M.erase(M.begin());
        if(ans[u]<w)
            continue;
        for(int i=first[u];i;i=E[i].next)
        {
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
	freopen("std.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            first[i]=0;
        res=en=0;
        for(int i=1,c;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            E[++en]=(edge){v,first[u],c};
            first[u]=en;
            E[++en]=(edge){u,first[v],c};
            first[v]=en;
        }
        for(int i=1;i<=n;i++)
        {
            Dij(i);
            for(int j=1;j<=n;j++)
                if(i!=j)
                    (res+=ans[j].second)%=mo;
        }
        printf("%lld\n",res);
    }
    return 0;
}
