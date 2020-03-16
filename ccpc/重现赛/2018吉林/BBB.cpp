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
priority_queue<LL> a;
int main()
{
    LL ans=0;
    F(i,1,5){
        LL x=read();
        a.push(x);
    }
    while(a.size()>=2){
        LL mx=a.top();a.pop();
        LL mx2=a.top();a.pop();
        //cout<<mx<<' '<<mx2<<endl;
        ans+=mx2;
        if(mx-mx2>0) a.push(mx-mx2);
    }
    cout<<ans<<endl;
    //a[1]=read();a[2]=read();a[3]=read();a[4]=read();a[5]=read();
    return 0;
}