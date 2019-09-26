//
// Created by 赵婉如 on 2019-07-23.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define inf 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=300010;
LL a[N];
LL sum[N];
LL dp[N];
int main()
{
    int n=read();int m=read();int k=read();
    F(i,1,n) a[i]=read();
    F(i,1,n) sum[i]=sum[i-1]+a[i];
    LL ans=0;
    F(i,1,min(m,n)){
        ans=max(ans,sum[i]-sum[0]-k);
    }
    F(i,1,n){
        if(i>=m){
            LL bst=sum[i]-sum[i-m]-k;//(i-m+1,i)
            if(i>=m+1) bst+=dp[i-m];
            dp[i]=max(dp[i],+bst);//
        }
        F(j,1,min(m,n-i)){//length
            ans=max(ans,dp[i]+sum[i+j-1]-sum[i]-k*(j>1));
        }
    }/*
    F(i,1,n){
        LL t=-inf;
        F(j,1,m) {
            t=max(t,sum[i+j]-sum[i-1]);
        }
    }*/
    for(int i=1;i<=n;i++){
        cout<<sum[i]<<' ';
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}
//0 0 3 0 6 2 5