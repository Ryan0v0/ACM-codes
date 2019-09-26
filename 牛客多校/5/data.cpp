//
// Created by 赵婉如 on 2019-08-01.
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
int b,c;
int main()
{
    int tt=20;        srand(time(NULL));
    cout<<(1<<2)<<endl;
    while(tt--) {
        int x = rand() % 50 + 1;
        int y = rand() % 50 + 1;
        int a = rand() % ((int) (sqrt(x * x + y * y) - 1)) + 1;
        do {
            b = rand() % a;
            c = rand() % a;
        } while (!((b + c) > a && (b - c) < a));
        cout << x << ' ' << y << ' ' << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}
/*
26 29 34 27 17
36 11 32 18 21
13 3 7 3 6
2 38 5 4 4
32 42 16 7 12
8 33 5 4 2

*/