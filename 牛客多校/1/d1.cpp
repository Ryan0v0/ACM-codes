//
// Created by 赵婉如 on 2019-08-23.
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
const int N=500010;
const LL INF=1000000000000000LL;
LL X[N],S[N];
LL sum[N];
LL ans;
multiset<LL> mt;
multiset<LL>::iterator it;
int main()
{
    int tt=read();
    F(Case,1,tt){
        cout<<"Case #"<<Case<<": ";
        int n,odd;LL mx;
        n=read();odd=read();mx=read();
        LL A,B,C,M,L;
        X[1]=read();X[2]=read();A=read();B=read();C=read();
        M=read();L=read();
        //scanf("%d%d%d%d%d%d%d",&X[1],&X[2],&A,&B,&C,&M,&L);
        F(i,3,n) X[i]=((A*X[i-1]%M+B*X[i-2]%M)%M+C)%M;
        F(i,1,n) S[i]=X[i]+L;//,printf("%lld ",S[i]);puts("");//cout<<S[i]<<' ';cout<<endl;
        sum[0]=0;
        F(i,1,n) sum[i]=sum[i-1]+S[i];

        int r=1;int num=0;//number of the odd
        mt.clear();
        ans=-INF;//cout<<"ans="<<ans<<' '<<-INF<<endl;
        //printf("ans=%lld %lld\n",ans,-INF);
        F(l,1,n){
            while(r<=n && num+(S[r]&1)<=odd){
                mt.insert(sum[r]);
                num+=(S[r]&1);
                r++;
            }
            if(r<=l) r=l+1;
            else{
                it=mt.lower_bound(mx+sum[l-1]+1);
                if(it!=mt.begin()){
                    it--;
                    ans=max(ans,(*it)-sum[l-1]);
                }
                mt.erase(mt.find(sum[l]));
                num-=(S[l]&1);
            }
        }
        if(ans==-INF) cout<<"IMPOSSIBLE"<<endl;
        else printf("%lld\n",ans);//cout<<ans<<endl;
    }
    return 0;
}
/*
5
6 1 1000000000000000
1 1 1 1 0 100 0
6 1 -100
1 1 1 1 0 100 0
10 1 8
4 3 4 1 5 20 -10
10 2 8
4 3 4 1 5 20 -10
10 1 8
4 3 4 1 5 20 -19

 */