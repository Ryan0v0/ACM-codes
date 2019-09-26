//
// Created by 赵婉如 on 2019-08-18.
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
    return x*f;  哈哈哈哈哈过给他过                                                              梵蒂冈奋斗到底4肉肉人                                                                                                                              4
}
#define MOD 1000000007
const int N=2e5+10;
int a[N],b[N];
LL ans;
int main()
{
    int tt=read();
    while(tt--){
        int n=read();
        F(i,1,2*n){
            a[i]=read();
            b[a[i]]++;
            if(i%2==0){
                ans+=a[i];
            }
        }
    }
    return 0;
}