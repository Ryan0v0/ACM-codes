//
// Created by 赵婉如 on 2019-08-20.
//
#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
int f[10005];
int d[10005];
int main()
{
    F(x,1,10) F(y,1,10) {
            cout<<"x="<<x<<" y="<<y<<endl;
            for (int n = 1; n <= 100; n++) {
                f[0] = f[1] = 1;
                for (int i = 2; i <= 10000; i++)
                    f[i] = (x*f[i - 1] + y*f[i - 2]) % n;
                for (int i = 0; i <= 9999; i++)
                    d[i] = (f[i] + 2 * f[i + 1]) % n;
                for (int j = 1; j <= 5000; j++) {
                    bool flag = true;
                    for (int k = 0; k <= j && flag; k++)
                        if (d[k] != d[k + j])
                            flag = false;
                    if (flag) {
                        printf("n=%d xhj=%d\n", n, j);
                        break;
                    }
                }
            }
        }
    return 0;
}
