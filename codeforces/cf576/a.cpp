//
// Created by 赵婉如 on 2019-08-07.
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
int n;
int x,y;
int a[N];
int main()
{
    n=read();x=read();y=read();
    F(i,1,n) a[i]=read();
    bool flag=1;
    F(i,1,n){
        flag=1;
        F(j,1,x) if(i-j>=1 && a[i-j]<=a[i]) flag=0;
        F(j,1,y) if(i+j<=n && a[i+j]<=a[i]) flag=0;
        if(flag){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}