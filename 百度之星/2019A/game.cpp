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
const int N=1010;
struct node{
    int l,r;
}a[N];
bool cmp(const node a,const node b)
{
    return a.l<b.l||(a.l==b.l&&a.r<b.r);
}
vector<node> v;
int ans;
int main()
{
    int tt=read();
    while(tt--){
        int n=read();
        F(i,1,n) a[i].l=read(),a[i].r=read();
        //sort(a+1,a+n+1,cmp);
        //F(i,1,n) cout<<a[i].l<<' '<<a[i].r<<endl;
        v.clear();
        ans=0;
        int l=a[1].l;int r=a[1].r;
        F(i,2,n){
            //cout<<l<<' '<<r<<endl;
            if((a[i].l>=l&&a[i].l<=r)||(a[i].r>=l&&a[i].r<=r)){
                l=max(l,a[i].l);
                r=min(r,a[i].r);
            }else{
                v.push_back((node){l,r});
                l=a[i].l,r=a[i].r;
            }
        }
        v.push_back((node){l,r});
        int pos=0;
        cout<<"size="<<v.size()<<endl;
        F(i,0,v.size()-1) cout<<"!!!"<<v[i].l<<' '<<v[i].r<<endl;
        if(v[1].l>v[0].r) ans+=v[1].l-v[0].r,pos=v[1].l;
        else if(v[1].r<v[0].l) ans+=v[1].r-v[0].l,pos=v[1].r;
        F(i,2,v.size()-1){
            cout<<"pos="<<pos<<endl;
            if(v[i].l>v[i-1].r) ans+=(v[i].l-pos),pos=v[i].l;
            else if(v[i].r<v[i-1].l) ans+=(pos-v[i].r),pos=v[i].r;
            //ans+=v[i]
        }
        //int d=v[v.size()-1].l-v[0].r;
        int res;
        if(ans%2==1) res=ans/2+1;
        else res=ans/2;
        cout<<res<<endl;
    }
    return 0;
}
/*
3
2
1 10
20 30
5
1 10
17 19
2 7
5 30
1 3
11
10 15
33 36
1 50
1 30
33 70
33 58
10 22
10 37
1 20
10 60
33 47

 */