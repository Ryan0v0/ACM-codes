//
// Created by 赵婉如 on 2019-08-24.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 1000000000000000000
#define pa pair<LL,int>
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
#define mod 998244353
int n,m,tot;
pa d[1005][1005];
//LL f[1005][1005];
LL ans;
int head[1005];
bool v[1005];
struct edge{int go,next;LL w;}e[50005];
void add(int x,int y,LL z)
{
    e[++tot].go=y;e[tot].w=z;e[tot].next=head[x];head[x]=tot;
}
int pre[1005][1005];
#define pa1 pair<pa,int>
void dijkstra(int s)
{
    priority_queue<pa1,vector<pa1>,greater<pa1> >q;
    for(int i=0;i<=n;i++) d[s][i]=make_pair(inf,-1);
    d[s][0]=make_pair(inf,0);
    //for(int i=0;i<=n;i++) d[s][i]=make_pair(inf,-1);
    memset(v,0,sizeof(v));
    d[s][s]=make_pair(0,0);q.push(make_pair(d[s][s],s));
    //f[s][s]=0;
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(v[x])continue;v[x]=1;
        for(int i=head[x];i;i=e[i].next) {
            int y=e[i].go;
            //cout<<"y="<<y<<endl;
            if (d[s][x].first + e[i].w < d[s][y].first ) {
                d[s][y].first = d[s][x].first + e[i].w;
                d[s][y].second = max(d[s][x].second, y);
                //cout<<s<<' '<<x<<' '<<y<<endl;
                //f[s][y]=max((LL)y,f[s][x]);
                pre[s][y] = x;
                q.push(make_pair(d[s][y], y));
            }else if(d[s][x].first + e[i].w == d[s][y].first && max(d[s][x].second, y)<d[s][y].second){
                d[s][y].second = max(d[s][x].second, y);
                pre[s][y] = x;
                q.push(make_pair(d[s][y], y));
            }
        }
    }
}
int main()
{
    int tt=read();
    while(tt--){
        n=read();m=read();ans=0;
        //F(i,1,n) mec(f[i],0);
        mec(head,0);tot=0;mec(pre,0);
        F(i,1,n) {
            int x=read();int y=read();LL z=read();
            add(x,y,z);
            add(y,x,z);
        }
        F(i,1,n) dijkstra(i);
        /*F(i,1,n) {
            F(j,1,n) cout<<f[i][j]<<' ';
            cout<<endl;
        }*/
        F(i,1,n) {
            F(j,1,n)cout<<pre[i][j]<<' ';
            cout<<endl;
        }
        F(i,1,n) {
            F(j,1,n)cout<<d[i][j].first<<' ';
            cout<<endl;
        }
        F(i,1,n) {
            F(j,1,n)cout<<d[i][j].second<<' ';
            cout<<endl;
        }
        F(i,1,n) {
            F(j,1,n)cout<<d[i][pre[i][j]].second<<' ';
            cout<<endl;
        }
        F(i,1,n) F(j,1,n) ans=(ans+d[i][pre[i][j]].second)%mod;
        cout<<ans<<endl;
    }
    return 0;
}
/*
2
4 4
1 2 1
2 3 1
3 4 1
4 1 1
6 8
1 2 1
1 3 1
2 3 1
2 4 1
3 4 1
3 5 1
4 5 1
4 6 1

 */