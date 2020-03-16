//
// Created by 赵婉如 on 2019-10-08.
//

#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
const int N=3e5+10;
LL n;
char s[N];
int a[N];
int main()
{
    n=read();
    scanf("%s",s+1);
    F(i,1,n){
        if(s[i]=='A') a[i]=0;
        else if(s[i]=='B') a[i]=1;
    }
    LL cnt=0,cnt1=0,cnt2=0;
    F(i,1,n-1){
        if(a[i+1]!=a[i]){
            cnt1+=i;
            //cout<<i<<endl;
            break;
        }
    }
    D(i,n,2){
        if(a[i-1]!=a[i]){
            cnt2+=(n-i+1);
            //cout<<i<<endl;
            break;
        }
    }
    LL tmp1=0,tmp2=0;
    F(i,1,n-1){
        if(a[i]==0&&a[i+1]==1) tmp1++;
        if(a[i]==1&&a[i+1]==0) tmp2++;
    }
    if(cnt1&&cnt2) cnt=2*n-(cnt1+cnt2)-tmp1-tmp2;
    else cnt=0;
    //if(tmp1>1) cnt-=(tmp1-1);
    //if(tmp2>1) cnt-=(tmp2-1);
    //cout<<tmp1<<' '<<tmp2<<' '<<cnt<<endl;
    LL tot=(n-1)*n/2;
    cout<<tot-cnt<<endl;
    return 0;
}