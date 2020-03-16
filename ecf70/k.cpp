//
// Created by 赵婉如 on 2019-08-22.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a,x) memset(a,x,sizeof(a))
#define INF 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=4e5+10;
int n,m;
int deg[N];
int  tot=0,head[N];
struct edge{int fro,go,next;}e[N];
void add(int x,int y)
{
    e[++tot]=(edge){x,y,head[x]};head[x]=tot;
}
priority_queue<int,vector<int>,greater<int>> q;
vector<int> v;
bool vis[N];
int main()
{
    n=read();m=read();/*
    F(i,1,n-1){
        add(i,i+1);
        deg[i+1]++;
    }*/
    F(i,1,m){
        int x=read();int y=read();
        deg[y]++;
        add(x,y);
    }
    F(i,1,n) if(!deg[i]) q.push(i),vis[i]=1;
    while(!q.empty()){
        int x=q.top();q.pop();
        cout<<x<<' ';cout<<endl;
        v.push_back(x);
        R(i,x){
            int y=e[i].go;
            //cout<<x<<' '<<y<<endl;
            if(vis[y]) continue;
            deg[y]--;
            if(!deg[y]) q.push(y),vis[y]=1;
        }
    }
    F(i,0,v.size()-1) cout<<v[i]<<' ';cout<<endl;
    return 0;
}
/*
3 1
3 1l

5 6
2 1
5 2
4 1
5 4
3 1
5 3

5 3
3 1
1 5
2 4

5 2
3 1
1 5

 */