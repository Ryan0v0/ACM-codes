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
const int N=100010;
int n;
int x,y;
int a[N];
int l[N],r[N];
int main()
{
    n=read();x=read();y=read();
    F(i,1,n) a[i]=read();
    l[1]=1;r[n]=n;
    F(i,2,n){
        if(a[i-1]>a[i]) l[i]=l[i-1];
        else l[i]=i;
        //cout<<"l="<<l[i]<<endl;
    }
    D(i,n-1,1){
        if(a[i+1]>a[i]) r[i]=r[i+1];
        else r[i]=i;
    }
    //F(i,1,n) cout<<l[i]<<' '<<r[i]<<endl;
    F(i,1,n){
        if(max(1,i-x)>=l[i]&&min(n,i+y)<=r[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    //return 0;
}
/*
5 5 5
10 100 1000 10000 100000

10 3 3
19 7 15 13 18 16 9 2 4 5
*/