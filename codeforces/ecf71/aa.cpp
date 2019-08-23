//
// Created by 赵婉如 on 2019-08-22.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define INF 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
int ans=0;
int main()
{
    int tt=read();
    while(tt--){
        ans=0;
        int b=read();int p=read();int f=read();
        int h=read();int c=read();
        if(h>c){
            int t=min(b/2,p);
            ans+=t*h;
            ans+=min((b-t*2)/2,f)*c;
            cout<<ans<<endl;
        }else{
            int t=min(b/2,f);
            ans+=t*c;
            ans+=min((b-t*2)/2,p)*h;
            cout<<ans<<endl;
        }
    }
    return 0;
}
