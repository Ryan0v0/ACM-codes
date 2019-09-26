//
// Created by 赵婉如 on 2019-07-28.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define inf 100000000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=100010;
int k,n;
LL c[N],a[N],x[N];
LL ans,sum;
int main()
{
    int tt=read();
    F(Case,1,tt){
        k=read();n=read();ans=inf;
        F(i,1,n) x[i]=read();
        F(i,1,n){
            c[i]=read();
        }
        F(i,1,n){
            mec(a,0);sum=c[i];
            F(j,1,n){
                if(i==j) a[i]=inf;
                else a[j]=c[j]+abs(x[i]-x[j]);
            }
            sort(a+1,a+n+1);
            F(j,1,k) sum+=a[j];
            ans=min(ans,sum);
        }
        cout<<"Case #"<<Case<<": "<<ans<<endl;
    }
    return 0;
}

/*
3
2 4
1 2 3 10
100 70 80 20
1 5
150 300 301 400 700
8 35 26 5 2
6 7
22 21 20 23 26 25 24
10 10 10 10 10 10 10

*/