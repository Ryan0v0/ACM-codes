//
// Created by 赵婉如 on 2019-09-23.
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
const int N=1e4;
LL a[N],b[N];
int cnt[N];
vector<int> v[N];
priority_queue<pair<int,int>> s;
LL ans;
int vis[N];
int siz;
int main()
{
    int n=read();siz=n;
    F(i,1,n) a[i]=read();
    F(i,1,n) b[i]=read(),ans+=b[i];
    F(i,1,n) F(j,1,n) if(i!=j&&((a[i]&a[j])<a[i])) v[j].push_back(i),cnt[i]++;
    F(i,1,n) s.push(make_pair(cnt[i],i));
    while(!s.empty()){
        auto x=s.top();s.pop();
        if(vis[x.second]){
            s.push(make_pair(x.first-vis[x.second],x.second));
            vis[x.second]=0;
        }
        else{
            if(x.first==siz-1){
                siz--;
                ans-=b[x.second];
                for(auto y:v[x.second]) vis[y]++;
            }
            else break;
        }
    }/*
    do{
        flag=0;
        for(int i=0;i<n;i++) if(!vis[i]){
            int cnt = 0;
            LL x = a[i];
            for (int j=0;j<n;j++) if(!vis[j]){
                LL y = a[j];
                if ((x & y) < x) cnt++;
            }
            if (cnt == siz-1){
                vis[i]=1;flag=1;siz--;
                break;
            }
        }
    }while(flag);
    F(i,0,n-1) if(!vis[i]) ans+=b[i];*/
    cout<<ans<<endl;
    return 0;
}