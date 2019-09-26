//
// Created by 赵婉如 on 2019-08-30.
//

//
// Created by 赵婉如 on 2019-08-30.
//

//
// Created by 赵婉如 on 2019-08-30.
//

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
const int N=1e6+10,M=2e5+10;
LL a[20],sum[20][20];
LL n;
LL m;
int main()
{
    //for(int i=0;i<=100;i+=7) cout<<i<<' '<<i%10<<endl;
    int q=read();
    a[0]=0;
    F(i,0,10) sum[0][i]=0;
    F(i,1,9){
        sum[i][0]=0;
        F(j,1,10) a[i]+=(i*j)%10,sum[i][j]=a[i];
        //F(j,1,10) a[i]+=(a[i]+i)%10,sum[i][j]=a[i],cout<<a[i]<<"***"<<endl;
        //cout<<i<<' '<<a[i]<<endl;
    }
    while(q--){
        n=read();m=read();
        LL t=n/m;
        //cout<<t<<' '<<m/n<<' '<<t%10<<endl;
        LL ans=t/10*a[m%10]+sum[m%10][t%10];
        cout<<ans<<endl;
    }
    return 0;
}