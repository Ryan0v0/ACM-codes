//
// Created by 赵婉如 on 2019-08-31.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
#define INF 1000000000
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0LL, f = 1LL;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1LL;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10LL * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int n,m;
int main()
{
    int tt = read();
    F(Case, 1, tt) {
        cout << "Case #" << Case << ": ";
        n=read();m=read();
        double res1=0.5;
        if(n==1) res1=1;
        //cout<<0.500000<<' ';
        double res=((double)m+1.0)/((double)m*2.0);
        printf("%.6lf %.6lf\n",res1,res);
    }
    return 0;
}
/*
100
1 1
2 2
3 3
4 4
5 5
50 50

 */
