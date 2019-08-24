//
// Created by 赵婉如 on 2019-08-23.
//
#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}

LL dp[20][10][2];
LL calc(int pos,int sum,bool flag,const string & num)
//flag表示是否为边界情况
{
    if(pos==num.size()) return sum!=0;//保证不是9的倍数
    if(dp[pos][sum][flag]!=-1) return dp[pos][sum][flag];

    int lim=flag?num[pos]-'0':8;
    if(lim==9) lim=8;//调整上界
    LL res=0;
    F(i,0,lim){//枚举下一位(低一位)
        res+=calc(pos+1,(sum+i)%9,flag&&i==lim,num);
    }
    return dp[pos][sum][flag]=res;
}
LL solve(LL n)
{
    mec(dp,-1);
    string s=to_string(n);
    return calc(0,0,1,s);
}
int main()
{
    int tt=read();
    F(Case,1,tt){
        LL L=read();LL R=read();
        LL ans=solve(R)-solve(L-1);
        cout<<"Case #"<<Case<<": "<<ans<<endl;
    }
    return 0;
}