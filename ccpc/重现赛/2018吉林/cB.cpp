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
const int N=1e5+10;
LL n,r;
LL a[N];
LL res;
int main()
{
    int tt=read();
    while(tt--){
        n=read();r=read();
        F(i,1,n) a[i]=read();
        //res=1000000000;
        sort(a+1,a+n+1);
        LL cnt=unique(a+1,a+n+1)-(a+1);
        res=cnt;
        //cout<<"cnt="<<cnt<<endl;
        F(i,2,cnt){
            LL cur=max((a[i-1]-1)/r+1,cnt-i+1);
            res=min(res,cur);
        }
        res=min(res,(a[cnt]-1)/r+1);
        cout<<res<<endl;
        //puts("here");
    }
    return 0;
}
/*
2
3 2
1 3 5
4 1
5 2 3

 */