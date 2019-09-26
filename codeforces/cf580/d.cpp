//
// Created by 赵婉如 on 2019-08-20.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=100010;
int n;
LL a[N];
bool ok;
LL cnt,mn;
LL dis[N];
vector<int> G[N];
LL ans;
void dij(int x)
{
    F(i,1,n) dis[i]=N;
    dis[x]=0LL;
    queue<int> q;
    while(!q.empty()){
        int x=;
        for(int y:G[x]){
            if(dis[y]==N){
                dis[y]=dis[x]+1;
                q.push(y);
            }else if(dis[y]>=dis[x]){
                ans=min(ans,dis[y]+dis[x]+1);
            }
        }
    }
}
int main()
{
    n=read();ok=false;mn=(LL)1e18;
    F(i,1,n) a[i]=read();
    F(i,0,64) {
        cnt=0LL;
        F(j,1,n){
            if((a[j]>>i)&1){
                cnt++;
            }
        }
        cout<<i<<' '<<cnt<<endl;
        if(cnt>3){
            puts("3");
            return 0;
        }
        //mn=min(cnt,mn);
    }
    F(i,1,n) F(j,i+1,n) {
        if((a[i]&a[j])!=0){
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }
    F(i,1,n){
        dij(i);
    }
    //if(!ok) puts("-1");
    //else cout<<mn<<endl;
    return 0;
}