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
const int N=100010;//1024
int g[N][N];
int n;
bool check(int x)
{
    F(i, 1, n - 1) {
        int ans = 0;
        F(j, 1, n) {
            ans += g[i][j] * g[i + 1][j];
        }
        //cout<<x<<' '<<ans<<endl;
        if(ans!=0) return false;
    }
    return true;
}/*
int main()
{
    while(~scanf("%d",&n)) {
        cout<<"n="<<n<<endl;
        //int n = read();
        //int k = log2(n);
        F(k,1,n) {
            cout<<"k="<<k<<endl;
            //mec(g,0);
            F(i, 1, n) F(j, 1, n) g[i][j] = 1;
            F(i, 1, n) {
                F(j, 1, k) {
                    int t = i + j - 1;
                    if (t > n) t -= n;
                    g[i][t] = -1;
                }
            }
            F(i, 1, n) {
                F(j, 1, n) cout << g[i][j] << ' ';
                cout << endl;
            }
            if(check(k)){
                cout<<"ansK="<<k<<endl;
                //break;
            }
        }

    }
    return 0;
}*/
void dfs()
{

}
int main()
{
    return 0;
}