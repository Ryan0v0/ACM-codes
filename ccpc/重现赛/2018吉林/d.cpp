//
// Created by 赵婉如 on 2019-09-29.
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
const int N=250;
double dp[N],p;
int main()
{
    int tt=read();
    F(Case,1,tt) {
        cout << "Case " << Case << ": ";
        scanf("%lf",&p);mec(dp,0);
        double exp=100.0/p;
        //cout<<"exp="<<exp<<endl;
        dp[200]=exp;
        for(int i=199;i>=4;i--){
            dp[i]=1.0+p/100.0*(1.0-i/200.0)*dp[min(i+4,200)]+(1.0-p/100.0)*dp[min(i+3,200)];
        }
        printf("%.15lf\n",dp[4]);
        //cout<<dp[4]<<endl;
    }
    return 0;
}