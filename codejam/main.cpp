//
// Created by 赵婉如 on 2019-08-25.
//
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
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
char str[200];
int n,ans,len;
bool flag;
void dfs(int x)
{
    if(x==n+1){
        //flag=true;
        ans=max(ans,len);
        return;
    }
    F(i,x+1,n){
        if()
    }

}
void solve()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    len=0;flag=false;
    F(i,1,n){

    }
}
int main()
{
    int tt=read();
    F(Case,1,tt) {
        cout << "Case #" << Case << ": ";
        solve();
    }
    return 0;
    return 0;
}