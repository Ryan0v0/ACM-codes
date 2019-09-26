//
// Created by 赵婉如 on 2019-07-18.
//

#include<cstdio>
#define mo 998244353
using namespace std;
using LL=long long;

int A[11][11][25],B[11][11][25],a[100005],h[12],n,l[100005];
LL p[25],ans;

int length(int x)
{
    if(x==0)
        return 0;
    return length(x/10)+1;
}

int main()
{
    p[0]=1;
    for(int i=1;i<=19;i++)
        p[i]=p[i-1]*10%mo;
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
        {
            int k,tot=0;
            for(k=1;k<25;k+=2)
                if(k+1>>1<=j)
                    A[i][j][k]=1,tot++;
                else
                    break;
            --k;
            while(tot<i)
                A[i][j][k++]=1,tot++;
        }
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
        {
            int k,tot=0;
            for(k=0;k<25;k+=2)
                if(k>>1<=j)
                    B[i][j][k]=1,tot++;
                else
                    break;
            --k;
            while(tot<i)
                B[i][j][k++]=1,tot++;
        }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),l[i]=length(a[i]),h[l[i]]++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=10;j++)
        {
            LL tot=0;
            int tmp=a[i];
            for(int k=0;k<20;k++)
                if(A[l[i]][j][k])
                    (tot+=tmp%10*p[k]%mo)%=mo,tmp/=10;
            (ans+=h[j]*tot%mo)%=mo;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=10;j++)
        {
            LL tot=0;
            int tmp=a[i];
            for(int k=0;k<20;k++)
                if(B[l[i]][j][k])
                    (tot+=tmp%10*p[k]%mo)%=mo,tmp/=10;
            (ans+=h[j]*tot%mo)%=mo;
        }
    printf("%lld",ans);
    return 0;
}