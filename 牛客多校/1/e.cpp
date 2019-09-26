//
// Created by 赵婉如 on 2019-07-19.
//

#include <bits/stdc++.h>
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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 2e3 + 5;
const int M = 50 + 5;
const ull seed = 131;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
ll dp[maxn][maxn];
int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i <= n + m; i++){
            for(int j = 0; j <= n + m; j++){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i = 0; i <= n + m; i++){
            for(int j = 0; j <= n + m; j++){
                if(i < n || (i - n) < min(m, j)){   //push A
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
                }
                if(j < m || (j - m) < min(n, i)){   //push B
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
                }
            }
        }
        printf("%lld\n", dp[n + m][n + m]);
    }
    return 0;
}