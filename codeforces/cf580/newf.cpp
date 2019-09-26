//
// Created by 赵婉如 on 2019-08-31.
//

#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 0x3f3f3f3f////
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
const int N=205,M=150000;
int d[N][N][N];
int id[M];
int n,m;
int w[M];
bool cmp(int x,int y){return w[x]<w[y];}
int main()
{
    int tt=read();
    F(Case, 1, tt) {
        cout << "Case #" << Case << ": " << endl;
        n = read();
        m = read();
        F(i,1,n) id[i]=i;
        F(i,1,n) w[i]=read();
        sort(id+1,id+n+1,cmp);
        //mec(d,inf);
        F(i,1,n) F(j,1,n) F(k,1,n) d[i][j][k]=inf;
        F(i,1,n) F(j,1,n) d[0][i][j]=read();
        F(k,1,n) F(i,1,n) F(j,1,n){
            d[k][i][j]=min(d[k-1][i][j],d[k-1][i][id[k]]+d[k-1][id[k]][j]);
        }
        while(m--){
            int x=read();int y=read();int i=0;
            int val=read();
            for(i=1;i<=n;i++) if(w[id[i]]>val) break; i--;
            cout<<d[i][x][y]<<endl;
        }
    }
    return 0;
}