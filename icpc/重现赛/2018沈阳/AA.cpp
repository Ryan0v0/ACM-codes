//
// Created by 赵婉如 on 2019-10-07.
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
int main()
{
    int n=read();int k=read();
    if(n==0){
        puts("Austin");
        return 0;
    }
    if(k==1){
        if(n&1) puts("Adrien");
        else puts("Austin");
        return 0;
    }
    puts("Adrien");
    return 0;
}