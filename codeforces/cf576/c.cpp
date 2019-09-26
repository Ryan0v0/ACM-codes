//
// Created by 赵婉如 on 2019-08-07.
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
const int N=4e5+10;
//int num[N];
map<int,int> num;//下标范围是1e9用map保存
int cnt;
int sum[N];
int main()
{//n个声音强度都是连续的值
    int n=read();int I=read();
    int k=I*8/n;
    int K=1<<min(20,k);
    F(i,1,n){
        int x=read();
        num[x]++;
    }
    for(auto x:num){//保证first从小到大
        cnt++;
        sum[cnt]=sum[cnt-1]+x.second;
    }
    int ans=n;
    F(i,1,cnt){
        int r=min(cnt,i+K-1);
        ans=min(ans,n-(sum[r]-sum[i-1]));
    }
    cout<<ans<<endl;
    return 0;
}