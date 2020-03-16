//
// Created by 赵婉如 on 2019-10-01.
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
int ans;
int main()
{
    int tt=read();
    while(tt--){
        LL a=read();LL b=read();
        LL c=read();LL d=read();
        if(a*c<0&&b*d<0){
            ans=8;
        }
        if(a*c<0&&b*d>0){
            ans=6;
        }
        if(a*c>0&&b*d<0){
            ans=6;
        }
        if(a*c>=0&&b*d>=0){
            ans=5;
        }
        if(a*c==0&&b*d<0||a*c<0&&b*d==0){
            ans=6;
        }
        cout<<ans<<endl;
    }
    return 0;
}