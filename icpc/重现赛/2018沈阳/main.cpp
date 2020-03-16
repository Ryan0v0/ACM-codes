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
}/*
int func(int n,int k)
{
    int res=0;
    F(i,1,m){
        res=(res+k)%i;
    }
    return res+1;
}*/
LL func(LL n,LL m,LL k)
{
    if(m==1){
        return (k-1)%n;
    }
    return (func(n-1,m-1,k)+k)%n;
}
int main()
{
    int tt=read();
    /*F(n,1,100) F(k,1,n){
        cout<<n<<' '<<k<<":"<<endl;
        F(m,1,n) cout<<func(n,m,k)<<' ';
        cout<<endl;
    }*/
    while(tt--){
        LL n=read();LL m=read();LL k=read();
        cout<<func(n,m,k)+1<<endl;
    }
    return 0;
}
/*
1000
1000 100 20

 */