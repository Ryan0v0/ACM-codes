//
// Created by 赵婉如 on 2019-07-27.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#define INF 2139062143
#define MAX 0x7ffffffffffffff
#define del(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
template<typename T>
inline void read(T&x)
{
    x=0;T k=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')k=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}x*=k;
}
const int maxn=10000+15;
struct Edge {
    int u,v,w;
    Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w) {}
};
vector<Edge> edge;
vector<int> G[maxn];
int ecnt;

inline void add_edge(int u,int v,int w) {
    edge.push_back(Edge(u,v,w));
    edge.push_back(Edge(v,u,w));
    ecnt+=2;
    G[u].push_back(ecnt-2);
    G[v].push_back(ecnt-1);
}

int dis[maxn][15];
bool vis[maxn][15];

int n,m,k,s,t;
priority_queue< pair< pair<int , int>,int > > q;
void dij() {
    del(dis,127);dis[s][0]=0;q.push(make_pair(make_pair(0,s),0));
    while(!q.empty()) {
        pair< pair<int , int>,int > Node=q.top();q.pop();
        pair<int,int> node=Node.first;
        int id=Node.second,u=node.second,d=-node.first;
        if(vis[u][id]) continue;
        vis[u][id]=1;
        for(int i=0;i<G[u].size();i++) {
            Edge &e=edge[G[u][i]];
            int v=e.v;
            if(dis[v][id]>d+e.w) {
                dis[v][id]=d+e.w;
                q.push(make_pair(make_pair(-dis[v][id],v),id));
            }
            if(id<k&&dis[v][id+1]>d) {
                dis[v][id+1]=d;
                q.push(make_pair(make_pair(-dis[v][id+1],v),id+1));
            }
        }
    }
    int ans=INF;
    for(int i=0;i<=k;i++) ans=min(ans,dis[t][i]);
    printf("%d\n",ans);
}

int main()
{
    read(n),read(m);
    read(s),read(t);read(k);
    for(int i=1,u,v,w;i<=m;i++) {
        read(u),read(v),read(w);
        add_edge(u,v,w);
    }
    dij();
    return 0;
}
/*
4 4 1 4 1
1 3 5
1 2 4
2 4 1
3 2 1

4 4 0 3 1
0 2 5
0 1 4
1 0 4
2 1 1
 */