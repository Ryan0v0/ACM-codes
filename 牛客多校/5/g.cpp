//
// Created by 赵婉如 on 2019-08-01.
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

const int N = 3010;
int n, m;
char s[N], t[N];
int a[N], b[N];
int num, ans, cnt;

int main() {
    int tt = read();
    while (tt--) {
        cnt = 0;
        n = read();
        m = read();
        scanf("%s", s + 1);
        scanf("%s", t + 1);num=0;cnt=0;ans=0;
        F(i, 1, n) a[i] = s[i] - '0';//cout<<a[i];cout<<endl;
        F(i, 1, m) {
            b[i] = t[i] - '0';
            num = num * 10 + b[i];
            //cout<<num<<"!!!"<<endl;
        }
        //cout<<"num="<<num<<endl;
        int p = 0;
        F(i, 0, (1 << n) - 1) {
            ans = 0;
            bool flag=0;bool no=0;
            F(j, 0, n-1) {
                if (i & (1 << j)) {
                    //flag=0;
                    if(flag==0&&!a[j+1]) no=1;
                    ans=ans*10+a[j+1];
                    if(flag==0) flag=1;
                }
            }
            //cout<<"ans="<<ans<<endl;
            if (ans > num && !no) cnt++;
        }
        cout <<cnt<<endl;
    }
    return 0;
}