//
// Created by 赵婉如 on 2019-08-30.
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
const int N=2e5+10;
int n,k;
vector<int> v[N];
int main()
{
    n=read();k=read();LL ans=(LL)1e9;
    F(i,1,n){
        int x=read();
        int cnt=0;
        while(x){
            v[x].push_back(cnt);
            cnt++;
            x/=2;
        }
        v[x].push_back(cnt);
    }
    F(i,0,(int)2e5){
        sort(v[i].begin(),v[i].end());
        LL res=0;
        if(v[i].size()<k) continue;
        F(j,0,k-1) res+=v[i][j];
        ans=min(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 5
1 1 1 2 8

*/