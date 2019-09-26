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
int a[N];
int n;
int count(int x)
{
    int cnt=0;
    while(x){
        cnt+=(x&1);
        x=x>>1;
    }
    return cnt;
}
void solve()
{
    int ans=0;
    F(i,0,n-1) F(j,i,n-1){
        int res=0;
        F(k,i,j) res=res xor a[k];
        if(count(res)%2==0){
            ans=max(ans,j-i+1);
            //cout<<ans<<endl;
        }
    }
    cout<<ans<<' ';
}
int main()
{
    int tt=read();
    F(Case,1,tt){
        n=read();int q=read();
        F(i,0,n-1) a[i]=read();
        cout<<"Case #"<<Case<<": ";
        while(q--){
            int x=read();int y=read();
            a[x]=y;
            solve();
        }
        cout<<endl;
    }
    return 0;
}
/*
2
4 3
10 21 3 7
1 13
0 32
2 22
5 1
14 1 15 20 26
4 26

*/