//
// Created by 赵婉如 on 2019-08-06.
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
const int N=100010;
LL a[N],b[N];
int main()
{
    int n=read();int k=read();
    F(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    F(i,1,n) b[i]=a[i]-a[i-1];
    F(i,1,n) cout<<b[i]<<' ';cout<<endl;
    //LL x=a[(n+1)/2];
    int cnt=1;
    int t=0;
    while((n+1)/2+cnt<=n&&k>=b[(n+1)/2+cnt]){
        cout<<b[(n+1)/2+cnt]<<' '<<k<<endl;
        k-=b[(n+1)/2+cnt];
        t++;
        if(t==cnt){
           t=0;
           cnt++;
        }
    }
    cout<<cnt<<endl;
    cout<<a[(1+n)/2+cnt-1]<<endl;
    //cout<<ans<<endl;
    return 0;
}