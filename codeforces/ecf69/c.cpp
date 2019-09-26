//
// Created by 赵婉如 on 2019-07-23.
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
const int N=300010;
int a[N],b[N];
int main()
{
    int n=read();int k=read();
    F(i,1,n) {
        a[i]=read();
    }
    int ans=a[n]-a[1];
    F(i,1,n-1) b[i]=a[i]-a[i+1];
    /*F(i,1,n-1){
        cout<<b[i]<<' ';
    }*/
    //cout<<endl;
    sort(b+1,b+n);
    F(i,1,k-1){
        ans+=b[i];
        //cout<<b[i]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
