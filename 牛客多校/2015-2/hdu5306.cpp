//
// Created by 赵婉如 on 2019-08-04.
//
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
const LL N=1e6+10;
const LL inf=0x3f3f3f3f3f3f3f3f;
LL a[N];
LL mx[N<<2],mn[N<<2],sum[N<<2];
void push_up(int p)
{
    mx[p] = max(mx[p<<1],mx[p<<1|1]);
    mn[p] = min(mn[p<<1],mn[p<<1|1]);
    sum[p]= sum[p<<1] + sum[p<<1|1];
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        mx[p] = mn[p] = a[l];
        return ;
    }
    int mid;
    mid = (l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    push_up(p);
}
LL get_mx(int p,int l,int r,int a,int b)
{
    if(a>b)return 0;
    if(l>=a&&r<=b)return mx[p];
    LL ans = -INF;
    int mid = (l+r)>>1;
    if(a<=mid)ans = max(ans,get_mx(p<<1,l,mid,a,b));
    if(b >mid)ans = max(ans,get_mx(p<<1|1,mid+1,r,a,b));
    return ans;
}
LL get_mn(int p,int l,int r,int a,int b)
{
    if(a>b)return 0;
    if(l>=a&&r<=b)return mn[p];
    LL ans = INF;
    int mid = (l+r)>>1;
    if(a<=mid)ans = min(ans,get_mn(p<<1,l,mid,a,b));
    if(b >mid)ans = min(ans,get_mn(p<<1|1,mid+1,r,a,b));
    return ans;
}
LL get_sum(int p,int l,int r,int a,int b)
{
    if(a>b)return 0;
    if(a<=l&&r<=b) return sum[p];
    LL ans = 0;
    int mid = (l+r)>>1;
    if(a<=mid)ans = ans+get_sum(p<<1,l,mid,a,b);
    if(b >mid)ans = ans+get_sum(p<<1|1,mid+1,r,a,b);
    return ans;
}
void update(int p,int l,int r,int a,int b)
{
    if()return;

}
int n,m;
int main()
{
    int tt=read();
    while(tt--){
        n=read();m=read();
        F(i,1,n) a[i]=read();
        build(1,1,n);
        while(m--){
            int opt=read();int l=read();int r=read();
            if(opt==0){
                int x=read();
                update(l,r,x);
            }
            else if(opt==1){
                cout<<get_mx(1,1,n,l,r)<<endl;
            }
            else if(opt==2){
                cout<<get_sum(1,1,n,l,r)<<endl;
            }
        }
    }
    return 0;
}