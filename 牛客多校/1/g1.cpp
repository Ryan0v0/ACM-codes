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
const int N=200010;
int n;
LL num[N],a[N];
LL mx,ans;
void solve()
{
    n=read();mec(num,0);mx=0;
    F(i,1,n){
        a[i]=read();
        num[a[i]]++;
        mx=max(a[i],mx);
    }
    LL ans=0;
    F(i,1,n) F(j,i+1,n){
        if(a[i]==1||a[j]==1||a[i]==0||a[j]==0) continue;
        if(a[i]*a[j]>mx) continue;
        ans+=num[a[i]*a[j]];
    }
    ans+=num[0]*(num[0]-1)*(num[0]-2)/6;//C(num[0],3);
    ans+=num[0]*(num[0]-1)/2*(n-num[0]);//C(num[0],2)*(n-num[0])

    ans+=num[1]*(num[1]-1)*(num[1]-2)/6;//C(num[1],3)
    F(i,2,mx) {
        ans+=num[1]*num[i]*(num[i]-1)/2;//num[1]*C(num[i],2);
    }
    cout<<ans<<endl;
}
int main()
{
    int tt=read();
    F(Case,1,tt) {
        cout << "Case #" << Case << ": ";
        solve();
    }
    return 0;
}