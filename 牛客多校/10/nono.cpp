//
// Created by 赵婉如 on 2019-08-17.
//


#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
LL a[100000], b[100000], m[100000];
LL gcd(LL a, LL b){
    return b ? gcd(b, a%b) : a;
}
void ex_gcd(LL a, LL b, LL &x, LL &y, LL &d){
    if (!b) {d = a, x = 1, y = 0;}
    else{
        ex_gcd(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}
LL inv(LL t, LL p){//如果不存在，返回-1
    LL d, x, y;
    ex_gcd(t, p, x, y, d);
    return d == 1 ? (x % p + p) % p : -1;
}
PLL linear(LL A[], LL B[], LL M[], LL n) {//求解A[i]x = B[i] (mod M[i]),总共n个线性方程组
    LL x = 0, m = 1;
    for(LL i = 0; i < n; i ++) {
        LL a = A[i] * m, b = B[i] - A[i]*x, d = gcd(M[i], a);
        if(b % d != 0)  return PLL(0, -1);//答案，不存在，返回-1
        LL t = b/d * inv(a/d, M[i]/d)%(M[i]/d);
        x = x + m*t;
        m *= M[i]/d;
    }
    x = (x % m + m ) % m;
    return PLL(x, m);//返回的x就是答案，m是最后的lcm值
}
int main(){
    LL n;LL cas=1;LL t;scanf("%lld",&t);
    while(t--){scanf("%lld", &n) ;
        for(LL i = 0; i < n; i ++){
            a[i] = 1;
            scanf("%lld%lld", &m[i], &b[i]);
        }
        PLL ans = linear(a, b, m, n);
        printf("Case %lld: ",cas++);
        if(ans.second == -1) printf("Impossible\n");
        else printf("%lld\n", ans.first);
    }
}
