#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 1000000000000000000
#define pa pair<LL,int>
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
LL p;
LL a[20],sum[20];
LL cost[20]={0,1,5,10,20,50,100,200,500,1000,2000};
LL ans;/*
bool flag=0;
void dfs(LL p,LL floor)
{
    if(flag) return ;
    if(p==0){
        cout<<ans<<endl;
        flag=1;
        return ;
    }
    if(floor==11){
        return;
    }
    D(i,a[floor],0) if(p>=i*cost[floor]){
        ans+=i;//cout<<"i="<<i<<endl;
        dfs(p-i*cost[floor],floor+1);
        ans-=i;
    }
}*/
void dfs(LL p,LL floor,LL res){
    if(p<0) return;
    if(floor==0) {
        if (p == 0) ans = max(ans, res);
        return;
    }
    LL tmp=p-sum[floor-1];
    LL num=0;
    if(tmp<0) num=0;
    else {
        num = tmp / cost[floor];
        if (tmp % cost[floor]) num++;
    }
    if(num<=a[floor]) dfs(p-num*cost[floor],floor-1,res+num);
    num++;
    if(num<=a[floor]) dfs(p-num*cost[floor],floor-1,res+num);
}
int main()
{
    int tt=read();
    while(tt--){
        ans=-1;mec(sum,0);//flag=0;
        p=read();
        F(i,1,10) a[i]=read();
        F(i,1,10) sum[i]=sum[i-1]+cost[i]*a[i];
        dfs(p,10,0);
        //if(!flag) cout<<"-1"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
/*
4
17 8 4 2 0 0 0 0 0 0 0
100 99 0 0 0 0 0 0 0 0 0
2015 9 8 7 6 5 4 3 2 1 0
150 0 0 0 6 3 1 0 0 0 0
 */