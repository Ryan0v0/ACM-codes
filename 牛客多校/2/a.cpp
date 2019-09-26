//
// Created by 赵婉如 on 2019-07-20.
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
LL n,m;
bool b[1000010];
int a[10000010];
void dfs(int x)
{
    bool flag=true;
    F(i,0,n-1){
        if(!b[i]){
            flag=false;
            break;
        }
    }
    if(flag){

    }
    b[(x+1)%n]=1;
    dfs((x+1)%n);
    b[(x+1)%n]=0;
    b[(x-1+n)%n]=1;
    dfs((x-1+n)%n);
    b[(x-1+n)%n]=0;
}
int main()
{
    int tt=read();
    while(tt--){
        n=read();
        dfs(0);
    }
    return 0;
}