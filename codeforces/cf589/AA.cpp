//
// Created by 赵婉如 on 2019-09-29.
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
bool vis[15];
bool check(int x)
{
    mec(vis,0);
    while(x){
        if(vis[x%10]) return false;
        vis[x%10]=1;
        x/=10;
    }
    return true;
}
int main()
{
    int x=read();int y=read();
    bool ok=false;
    F(i,x,y){
        if(check(i)){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
