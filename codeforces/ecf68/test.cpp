//
// Created by 赵婉如 on 2019-09-29.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
int n;
LL ans;
LL func(LL x)
{
    return (x*x+2LL*x);
}
int main()
{
    int tt=read();
    F(Case,1,tt){
        cout<<"Case "<<Case<<": ";
        n=Case;ans=0;
        F(i,1,n){
            ans+=(n/i);
        }
        //cout<<endl;
        //cout<<l<<endl;//cout<<"ans="<<ans<<endl;
        if(ans&1) cout<<"odd"<<endl;
        else cout<<"even"<<endl;
    }
    return 0;
}
/*
3
1
10000
100000000

 */