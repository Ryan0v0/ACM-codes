//
// Created by 赵婉如 on 2019-08-31.
//

#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
int w[150000],id[150000];
bool cmp(int x,int y) {return w[x]<w[y];}
int d[210][210][210];
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
int main()
{
    int tt=read();
    F(Case,1,tt){
        printf("Case #%d:\n", Case);
        int n=read(),q=read();
        F(i,1,n) id[i]=i,w[i]=read();
        sort(id + 1, id + n + 1, cmp);
        memset(d, INF, sizeof(d));
        F(i,1,n) F(j,1,n) d[0][i][j]=read();
        F(k,1,n) F(i,1,n) F(j,1,n) d[k][i][j] = min(d[k - 1][i][j], d[k - 1][i][id[k]] + d[k - 1][id[k]][j]);
        while (q--) {
            int x=read();int y=read();int val=read();int k=0;
            for (k = 1; k <= n; k++) if (w[id[k]] > val) break; k--;
            printf("%d\n", d[k][x][y]);
        }
    }
}
