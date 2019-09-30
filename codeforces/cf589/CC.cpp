//
// Created by 赵婉如 on 2019-09-29.
//

#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
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

#define MOD 1000000007

LL Pow(LL a, LL x) {
    LL res = 1LL;
    while (x) {
        if (x & 1LL) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        x >>= 1LL;
    }
    return res;
}

LL x, n;
LL ans;
const int N = 10010;
LL fac[N];int cnt;

void init(LL val) {
    int x = val;
    for (int i = 2; i*i<=x; i++) {
        //cout<<i<<' '<<x<<endl;
        int p = 0;
        while (x % i == 0) {
            x /= i;
            p++;
        }
        if (p) {
            fac[++cnt] = i;
            //cout<<cnt<<' '<<i<<endl;
        }
    }
    if(x>1) fac[++cnt]=x;
}

int main() {
    x = read();
    n = read();
    init(x);
    ans=1LL;
    F(i,1,cnt){
        //cout<<fac[i]<<' ';cout<<endl;
        LL cur=fac[i];
        LL num=0;
        while(cur<=n){
            //num=(num+n/cur%(MOD-1))%(MOD-1);
            num+=n/cur;
            if(cur>n/fac[i]) break;
            cur=cur*fac[i];
        }/*
        while(){
            num+=n/cur;
        }*/
        //cout<<num<<' '<<Pow(fac[i],num)<<endl;
        ans=ans*Pow(fac[i],num)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}