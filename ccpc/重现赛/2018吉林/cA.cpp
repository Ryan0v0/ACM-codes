//
// Created by 赵婉如 on 2019-10-08.
//

#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
    int tt=read();
    while(tt--) {
        LL x = read(), y = read();
        if (x - y == 1LL) puts("NO");
        else puts("YES");
    }
    return 0;
}