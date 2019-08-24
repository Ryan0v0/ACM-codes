//
// Created by 赵婉如 on 2019-08-24.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=100010;
int n,m,tot;
unordered_set<int> s;//zero
vector<int> G[N];
//vector<vector<int>> G(N,vector<int>());
bool v[N];
struct edge{
    int go;LL w;
    void init(){
        go=-1;
        LL w=-1;
    }
}e[N];//邻接
void update(int x,int y,LL z)
{
    if(e[x].go==-1){
        e[x].go=y;e[x].w=z;
    }else if(z<e[x].w){
        e[x].go=y;e[x].w=z;
    }
}
bool vis[N];
void dfs(int x)
{
    if(vis[x]) return;
    //cout<<x<<endl;
    vis[x]=1;
    F(i,0,(LL)G[x].size()-1){
        //cout<<x<<' '<<G[x][i]<<endl;
        dfs(G[x][i]);
    }
}
int main()
{
//    ios::sync_with_stdio(false);
    int tt=read();
    F(Case,1,tt){
        cout<<"Case #"<<Case<<": ";
        int cnt=0;mec(vis,0);
        s.clear();//G.clear();
        n=read();m=read();
        F(i,1,n) G[i].clear();
        F(i,1,n) e[i].init();/*
        cout<<"|^^^^^^^^^^^^|"<<endl;
        F(i,1,n) F(j,0,(LL)G[i].size()-1) cout<<i<<' '<<G[i][j]<<endl;
        cout<<"|____________|"<<endl;*/
        F(i,1,m){
            int x=read();int y=read();LL l=read();
            update(x,y,l);update(y,x,l);
            if(l==0){
                s.insert(x);
                s.insert(y);
            }
        }
        //F(i,1,n) cout<<i<<' '<<e[i].go<<' '<<e[i].w<<endl;
        /*cout<<"|^^^^^^^^^^^^|"<<endl;
        F(i,1,n) F(j,0,(LL)G[i].size()-1) cout<<i<<' '<<G[i][j]<<endl;
        cout<<"|____________|"<<endl;*/
        F(i,1,n) G[i].push_back(e[i].go),G[e[i].go].push_back(i);
        /*cout<<"|^^^^^^^^^^^^|"<<endl;
        F(i,1,n) F(j,0,(LL)G[i].size()-1) cout<<i<<' '<<G[i][j]<<endl;
        cout<<"|____________|"<<endl;*/
        F(i,1,n){
            if(!vis[i]){
                dfs(i);
                cnt++;
            }
        }
        cout<<cnt<<endl;
        F(i,1,n){
            if(s.find(e[i].go)!=s.end()){
                cnt++;
            }
        }
        //cout<<cnt<<' '<<s.size()<<endl;
        cnt-=s.size();
        cout<<(1LL<<cnt)<<endl;
    }
    return 0;
}
/*
2
3 3
1 2 1
1 3 6
2 3 4
6 5
1 2 6
3 4 0
5 6 7
3 5 1
4 6 2

 */