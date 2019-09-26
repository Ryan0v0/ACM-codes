#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define inf 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn=200010;
char s[maxn];
int sum[maxn],b[maxn];
int n,k,ans;
void solve(int x)
{
    //mec(sum,0);
    F(i,1,n) {
        //if(b[i]!=x) sum[i]=sum[i-1]+1;
        //else sum[i]=sum[i-1];
        sum[i]=sum[i-1]+(b[i]!=x);
        x++;
        x%=3;
    }
    F(i,k,n) ans = min(ans, sum[i] - sum[i - k]);
}
int main()
{
    int q=read();
    while(q--){
        n=read();k=read();ans=inf;
        scanf("%s",s+1);
        //cout<<"s="<<(s+1)<<endl;
        F(i,1,n){
            if(s[i]=='R') b[i]=0;
            else if(s[i]=='G') b[i]=1;
            else if(s[i]=='B') b[i]=2;
        }
        //F(i,1,n) cout<<b[i]<<' ';cout<<endl;
        F(i,0,2) solve(i);
        cout<<ans<<endl;
    }
    return 0;
}