#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=10010;
int f[N],g[N];
int p;
LL gcd(LL a, LL b) {return b?gcd(b,a%b):a;}
int main()
{
    int tt=read();
    while(tt--){
        int n=read();int p=0;
        F(i,1,n) f[i]=read();
        F(i,1,n) g[i]=read();
        D(i,n,1) if(f[i]!=0||g[i]!=0) {
            p=i;
            break;
        }
        if(p>0&&f[p]!=0&&g[p]!=0){
            int t=gcd(f[p],g[p]);
            printf("%d/%d\n",f[p]/t,g[p]/t);
        }else{
            if(p==0||f[p]==0) printf("0/1\n");
            else printf("1/0\n");
        }
    }
    return 0;
}