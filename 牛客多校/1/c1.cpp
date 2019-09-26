//
// Created by 赵婉如 on 2019-08-23.
//
#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
//给定一棵基环树
const int N=100010;
int n;
vector<int> G[N];
int deg[N];
bool vis[N];
int dis[N];
int main()
{
    //ios::sync_with_stdio(false);
    int tt=read();
    F(Case,1,tt){
        cout<<"Case #"<<Case<<": ";
        n=read();
        F(i,1,n) G[i].clear();
        mec(deg,0);mec(vis,0);mec(dis,0);
        F(i,1,n){
            int x=read();int y=read();
            G[x].push_back(y);
            G[y].push_back(x);
            deg[x]++;deg[y]++;
        }
        //F(i,1,n) cout<<deg[i]<<' ';cout<<endl;
        queue<int> q;//队列无clear()操作
        F(i,1,n) if(deg[i]==1) q.push(i);
        while(!q.empty()){
            int x=q.front();q.pop();
            vis[x]=1;
            F(i,0,(int)G[x].size()-1){
                int y=G[x][i];
                deg[y]--;
                if(deg[y]==1) q.push(y);
            }
        }
        //F(i,1,n) cout<<vis[i]<<' ';cout<<endl;//cout<<"***"<<q.size()<<endl;
        F(i,1,n) if(!vis[i]) dis[i]=0,q.push(i);
        while(!q.empty()){
            int x=q.front();q.pop();
            F(i,0,(int)G[x].size()-1){
                int y=G[x][i];
                if(vis[y]) {
                    dis[y] = dis[x] + 1;
                    q.push(y);//只有在环外的再加进去
                }
                //cout<<x<<' '<<y<<endl;
            }
        }
        F(i,1,n) cout<<dis[i]<<' ';cout<<endl;
    }
    return 0;
}
/*
2
5
1 2
2 3
3 4
2 4
5 3
3
1 2
3 2
1 3

 */