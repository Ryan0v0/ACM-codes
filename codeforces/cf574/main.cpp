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

int a[100010];
int ans;
int main()
{
    int n=read();int k=read();
    F(i,1,n){
        int x=read();
        a[x]++;
    }
    F(i,1,1000)
        ans+=a[i]/2;
    ans*=2;
    ans+=(n-ans+1)/2;
    cout<<ans<<endl;
    return 0;
}