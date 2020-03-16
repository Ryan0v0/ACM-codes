//
// Created by 赵婉如 on 2019-08-27.
//

#include<iostream>
#include<stdio.h>
using namespace std;
int v[11]={0,1,5,10,20,50,100,200,500,1000,2000};
int s[11];
int ans;int N;
long long T[11];
void dfs(int p,int n,int d)
{

    if(p<0) return ;
    if(d==0)
    {
        if(!p)
        ans=max(ans,n);
        return ;
    }
    long long tmp=max((long long)0,p-T[d-1]);
    int k=tmp/v[d]+(tmp%v[d]?1:0);

    if(k>s[d]) return ;
    dfs(p-k*v[d],k+n,d-1);

    k++;
    if(k<=s[d])
    dfs(p-k*v[d],k+n,d-1);
}
void dfs(int rest,int idx,int cnt)
{
    if(rest<0)
        return;
    if(idx==0)
    {
        if(rest==0)
            ans=max(ans,cnt);
        return;
    }
    ll cur = max(rest-sum[idx-1],(ll)0);
    int curnum=cur/val[idx];
    if(cur % val[idx])
        curnum++;
    if(curnum<=c[idx])
        dfs(rest-curnum*val[idx],idx-1,cnt+curnum);
    curnum++;
    if(curnum<=c[idx])
        dfs(rest-curnum*val[idx],idx-1,cnt+curnum);
}

int main()
{
    int c;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&N);
        for(int i=1;i<=10;i++)
        scanf("%d",&s[i]);
        T[0]=0;
        for(int i=1;i<=10;i++)
        {
            T[i]=T[i-1]+(long long)s[i]*(long long)v[i];
        }
        ans=0;
        dfs(N,0,10);

        if(!ans) printf("-1\n");
        else printf("%d\n",ans);
    }

}