//
// Created by 赵婉如 on 2019-08-12.
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
const int N=100010;
LL w[N];
LL s1,s2;
int main()
{
    int n=read();
    F(i,1,n){
        w[i]=read();
        s1+=w[i];
        s2+=w[i]*w[i];
    }
    //cout<<s1<<' '<<s2<<endl;
    F(i,1,n){
        cout<<s2+n*w[i]*w[i]-2*s1*w[i]<<' ';
    }
    return 0;
}
