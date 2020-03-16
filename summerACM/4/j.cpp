//
// Created by 赵婉如 on 2019-08-13.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
inline LL read() {
    LL x = 0LL, f = 1LL;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1LL;=
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10LL * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int N=550;
LL a[N];
LL ans;
int n,m;
int main()
{
    //freopen("jacking.in","r",stdin);
    int tt=read();
    //while(tt--){
    F(Case,1,tt){
        cout<<"Case "<<Case<<": "<<endl;
        int nn=read();mec(a,0);
        F(i,1,nn) a[i]=read();
        //sort(a+1,a+nn+1);
        int q=read();
        while(q--){
            n=read();m=read();
            if(n<m){
                puts("impossible");
            }else{
                //ans=a[n/m];
                LL p=floor(n/m);
                LL q=n/m+1;
                LL pmod=n-p*m;
                LL qmod=q*m-n;
                LL ans=(m-pmod)*a[p]+pmod*a[p+1];
                ans=min(ans,(m-qmod)*a[q]+qmod*a[q-1]);
                cout<<ans<<endl;//int tot=0;
            }
        }
    }
    return 0;
}
/*
2
3 1 1 1
2
3 1
2 1
6 15 12 10 13 19 28
5
1 1
1 4
4 3
4 4
6 6

 */