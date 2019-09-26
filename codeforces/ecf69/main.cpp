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
const int N=100010;
int a[N];
int main()
{
    int tt=read();
    while(tt--){
        int n=read();
        F(i,1,n){
            a[i]=read();
        }
        sort(a+1,a+n+1);
        //F(i,1,n) cout<<a[i]<<' ';cout<<endl;
        cout<<min(a[n-1]-1,n-2)<<endl;
    }
    return 0;
}