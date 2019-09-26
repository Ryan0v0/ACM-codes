//
// Created by 赵婉如 on 2019-08-24.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=200010;
int n,q,tot;
LL x[N],y[N],z[N],aa,bb,cc,mod,ans;
LL l[N],r[N],k[N],a[N],f[N],g[N];
void input()
{
    n=read();q=read();
    scanf("%d%d%d%d%d%d",&x[1],&x[2],&aa,&bb,&cc,&mod);
    F(i,3,n){
        x[i]=(aa*x[i-1]+bb*x[i-2]+cc)%mod;
    }
    scanf("%d%d%d%d%d%d",&y[1],&y[2],&aa,&bb,&cc,&mod);
    F(i,3,n){
        y[i]=(aa*y[i-1]+bb*y[i-2]+cc)%mod;
    }
    scanf("%d%d%d%d%d%d",&z[1],&z[2],&aa,&bb,&cc,&mod);
    F(i,3,q){
        z[i]=(aa*z[i-1]+bb*z[i-2]+cc)%mod;
    }
}
void init()
{
    F(i,1,n) l[i]=min(x[i],y[i])+1;
    F(i,1,n) r[i]=max(x[i],y[i])+2;
    F(i,1,q) k[i]=z[i]+1;

    tot=0;
    F(i,1,n) a[++tot]=l[i];
    F(i,1,n) a[++tot]=r[i];

    sort(a+1,a+tot+1);
    tot=unique(a+1,a+tot+1)-(a+1);
    F(i,1,n) l[i]=lower_bound(a+1,a+tot+1,l[i])-a;//从1开始
    F(i,1,n) r[i]=lower_bound(a+1,a+tot+1,r[i])-a;//从1开始
}
void solve()
{
    input();
    init();
    F(i,1,n) f[l[i]]++,f[r[i]]--;
    F(i,2,tot) f[i]+=f[i-1];
    F(i,1,n){
        cout<<l[i]<<' '<<r[i]<<endl;
    }
    cout<<"tot="<<tot<<endl;
    F(i,1,tot) cout<<f[i]<<' ';cout<<endl;
    D(i,tot,1){
        if(i==tot) g[i]=f[i];
        else g[i]=g[i+1]+f[i]*(a[i+1]-a[i]);
    }

    ans=0;
    F(i,1,q){
        if(k[i]>g[0]) continue;
        LL res=0;
        int l=1,r=tot;
        while(l<=r){
            int mid=(l+r)>>1;
            if(g[mid]>=k[i]){//注意g是从后向前的增长的
                res=mid;
                l=mid+1;
            }else r=mid-1;
        }
        LL tmp=a[res]+(g[res]-k[res])/f[res];//???
        ans+=tmp*i;
    }
    cout<<ans<<endl;
}
int main()
{
    int tt=read();
    F(Case,1,tt) {
        cout << "Case #" << Case << ": ";
        solve();
    }
    return 0;
}
/*
3
5 1
3 1 4 1 5 9
2 7 1 8 2 9
4 8 15 16 23 42
5 5
3 1 4 1 5 9
2 7 1 8 2 9
4 8 15 16 23 42
1 2
0 0 0 0 0 1
0 0 0 0 0 1
0 1 0 0 0 2

 */