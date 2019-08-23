//
// Created by 赵婉如 on 2019-08-22.
//
#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
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
#define MOD 998244353
const int N=3e6+10;
int n;
pair<int,int> a[N];
map<int,int> mp1;
map<int,int> mp2;
map<pair<int,int>,int> mp3;
LL fac[N];
LL ans;
int main()
{
    n=read();
    fac[0]=1;
    F(i,1,n) fac[i]=fac[i-1]*i%MOD;

    F(i,1,n){
        int x=read();int y=read();
        a[i].first=x;
        a[i].second=y;
        mp1[x]++;
        mp2[y]++;
        mp3[make_pair(x,y)]++;
    }
    sort(a+1,a+n+1);
    LL res1=1LL,res2=1LL,res3=1LL;
    for(auto i:mp1){
        res1=res1*fac[i.second]%MOD;
    }
    for(auto i:mp2){
        res2=res2*fac[i.second]%MOD;
    }
    F(i,1,n-1){
        if(a[i].second>a[i+1].second){
            res3=0;
            break;
        }
    }
    if(res3!=0) {
        for (auto i:mp3) {
            res3=res3*fac[i.second]%MOD;
        }
    }
    ans=(((fac[n]-res1+MOD)%MOD-res2+MOD)%MOD+res3)%MOD;
    cout<<ans<<endl;
    return 0;
}