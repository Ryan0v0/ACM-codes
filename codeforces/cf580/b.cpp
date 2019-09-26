//
// Created by 赵婉如 on 2019-08-20.
// RE 1 100010->10010
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
const int N=100010;
int a[N];
int cnt0,cnt1,cnt2;
LL ans;
int main()
{
    int n=read();
    F(i,1,n){
        a[i]=read();
        if(a[i]==0){
            cnt0++;
        }else{
            if(a[i]>0){
               ans+=(a[i]-1);
               cnt1++;
            }else if(a[i]<0){
                ans+=(-1-a[i]);
                cnt2++;
            }
        }
    }
    if(cnt0==0){
        if(cnt2&1) ans+=2;
    }else{
        ans+=cnt0;
    }
    cout<<ans<<endl;
    return 0;
}