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
const int N=1010;
int n,m;
char s[N];
LL a[N][10];
LL ans;
int main()
{
    n=read();m=read();
    F(i,1,n){
        scanf("%s",s+1);
        F(j,1,m){
            a[j][s[j]-'A'+1]++;
        }
    }
    //F(i,1,m) {F(j,1,5) cout<<a[i][j]<<' ';cout<<endl;}
    F(i,1,m){
        LL w=read();
        LL mx=0;
        F(j,1,5){
            mx=max(mx,a[i][j]);
        }
        ans+=w*mx;
    }
    cout<<ans<<endl;
    return 0;
}
/*
2 5
ABCDE
ABCED
5 4 2 3 1
 */