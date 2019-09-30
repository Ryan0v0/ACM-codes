//
// Created by 赵婉如 on 2019-09-27.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define LL long long
#define N 100005
using namespace std;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
LL a[N];
int main()
{
    int T=read(),ca=0;
    while(T--)
    {
        int n=read();LL res=1LL;ca++;
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=n;i;i--)a[i]-=a[i-1];
        for(int i=n-1;i;i--)
        {
            if(a[i]<=a[i+1]){res++;continue;}
            if(a[i]%a[i+1])
            {res+=a[i]/a[i+1]+1LL,a[i]=a[i]/(a[i]/a[i+1]+1LL);}
            else {res+=a[i]/a[i+1],a[i]=a[i+1];}
            //		printf("%d %d %lld\n",i,a[i],res);
        }
        printf("Case #%d: %I64d\n",ca,res);
    }
    return 0;
}

/*
100
5
19 38 57 59 100

 */