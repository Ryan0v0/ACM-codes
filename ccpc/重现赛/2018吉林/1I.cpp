//
// Created by 赵婉如 on 2019-10-02.
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
const int N=(int)1e6+10;
int n;
LL a[N];
int main()
{
    int tt=read();
    while(tt--){
        n=read();
        a[1]=0;
        F(i,2,n){
            LL x=read();
            a[i]=a[i-1]+x;
        }
        //F(i,1,n) cout<<a[i]<<' ';cout<<endl;
        LL len=0;cout<<len;LL ans=0;
        F(i,2,n){
            if(i%2==0){
                len+=a[n-(i/2-1)]-a[1+(i/2-1)];
            }
            ans+=len;
            cout<<' '<<ans;
        }
        cout<<endl;
    }
    return 0;
}
/*
10
5
2 3 1 4
2
1
6
2 5 1 3 8

 */