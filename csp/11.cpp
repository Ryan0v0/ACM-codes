//
// Created by 赵婉如 on 2019-09-23.
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
int a[5];
int sum;
bool flag;
int main()
{
    F(i,1,4) a[i]=read(),sum+=a[i];
    if(sum&1){
        puts("NO");
        return 0;
    }
    F(i,0,15){
        int s=0;
        if((i>>0)&1){
            s+=a[1];
        }
        if((i>>1)&1){
            s+=a[2];
        }
        if((i>>2)&1){
            s+=a[3];
        }
        if((i>>3)&1){
            s+=a[4];
        }
        if(s==sum/2){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}