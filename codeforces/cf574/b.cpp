//
// Created by 赵婉如 on 2019-07-17.
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
LL n,k;
int main()
{
    n=read();k=read();
    for(long long x=0LL;x<1000000;x++){
        if(((1LL+x)*x/2-(n-x))==k){
            cout<<n-x<<endl;
            return 0;
        }
    }
}