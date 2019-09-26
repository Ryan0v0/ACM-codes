//
// Created by 赵婉如 on 2019-07-17.
//

#include <cstdio>
using namespace std;

int dp[100005],n,k,T;

int main()
{
    dp[0]=0,dp[1]=1,dp[2]=1;
    for(int i=3;i<=100;i++)
        if(!dp[i-1]||!dp[i-2]||(i>=12&&!dp[i-12]))
            dp[i]=1;

    //for(int i=0;i<=100;i++)
        //printf("%d ",i);
    //printf("\n");
    for(int i=0;i<=100;i++)
        printf("%d %d\n",i,dp[i]);
    /*scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(k%3==0)
            puts(n%(k+1)%3==0&&n%(k+1)!=k?"Bob":"Alice");
        else
            puts(n%3==0?"Bob":"Alice");
    }*/
    return 0;
}