//
// Created by 赵婉如 on 2019-09-14.
//
#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
LL ans;
int main()
{
    int r=read();int y=read();int g=read();
    int n=read();
    F(i,1,n){
        int k=read();
        int t=read();
        switch(k){
            case 0:ans+=t;break;
            case 1:ans+=t;break;
            case 2:ans+=t+r;break;
            case 3:break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
30 3 30
8
0 10
1 5
0 11
2 2
0 6
0 3
3 10
0 3

 */