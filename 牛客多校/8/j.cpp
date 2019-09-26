//
// Created by 赵婉如 on 2019-08-10.
//

#include <bits/stdc++.h>
#define MOD 998244353
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
const int N=1010;//可优化空间
LL f[N][N];
LL ans;
bool b[N][N];
int main()
{
    int L=read();int d=read();int m=read();
    while(m--){
        int t=read();int p=read();
        b[t][p]=1;
    }
    f[0][0]=1;
    F(i,1,L) f[0][i]=0;
    for(int i=1;i<=L;i++){
        for(int j=0;j<=L;j++){
            for(int k=d;j+k<=L;j++){
                if(!b[i+1][j+k]) f[i+1][j+k]=(f[i+1][j+k]+f[i][j])%MOD;
            }
        }
    }
    F(i,1,L) ans+=f[i][L];
    cout<<ans<<endl;
    return 0;
}