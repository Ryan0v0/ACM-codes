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
set<int> s1,s2;
int main()
{
    int n=read();
    F(i,1,n){
        int x=read();
        s1.insert(x);
    }
    int m=read();
    F(i,1,m){
        int x=read();
        s2.insert(x);
    }
/*
    F(i,1,n) F(j,1,m){
        int x=s1[i]+s2[j];
        if(!s1.count(x)&&!s2.count(x)){
            cout<<s1[i]<<' '<<s2[j];
            return 0;
        }
    }*/
    for(int i:s1){
        for(int j:s2){
            int x=i+j;
            if(!s1.count(x)&&!s2.count(x)){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}