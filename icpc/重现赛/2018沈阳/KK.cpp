//
// Created by 赵婉如 on 2019-10-03.
//

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
LL n,m,K;
LL ans;
int main()
{
    int tt=read();
    F(Case,1,tt){
        cout<<"Case #"<<Case<<": ";
        n=read();m=read();K=read();
        if(K==1) ans=m;
        else if(K>=m){
            //cout<<"1~~~~ ";
            ans=(K-1)%(n-m+1);
            F(i,2,m){
                ans=(ans+K)%(n-m+i);
            }
            ans++;
        }else if(K<m){
            //cout<<"2~~~~ ";
            ans=(K-1)%(n-m+1)+1;
            LL cur_m=1LL;
            LL delta=n-m;
            while(cur_m<m){
                LL step=(cur_m+delta-ans)*1.0/(double)(K-1.0);
                if(!step) step++;
                if(cur_m+step>=m){
                    step=m-cur_m;
                }
                cur_m+=step;
                LL mod=cur_m+delta;
                //if(cur_m>=m) break;
                ans=(ans+K*step%mod-1+mod)%mod+1;
                //ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}