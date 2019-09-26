//
// Created by 赵婉如 on 2019-07-13.
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
LL a[100010];
int main()
{/*
    int n=read();
    F(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    LL sum=0LL;
    F(i,1,n){
        sum+=abs(a[i]-i);
        if(a[i]-i<0){
            puts("cslnb");
            return 0;
        }
    }
    if(sum%2==1) puts("cslnb");
    else puts("sjfnb");
    return 0;*/
    cout<<(3&1)<<endl;
}