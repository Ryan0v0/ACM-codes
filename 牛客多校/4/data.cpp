//
// Created by 赵婉如 on 2019-07-27.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define INF 1000000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    freopen("in.txt","w",stdout);
    srand(time(NULL));
    int n=rand()%10+1;cout<<n<<endl;
    F(i,1,n) cout<<rand()%20-10<<' ';cout<<endl;
    F(i,1,n) cout<<rand()%20-10<<' ';cout<<endl;
    return 0;
}
/*
85
98 79 9 61 -80 -58 -88 45 37 -74 78 1 95 -95 -18 42 -64 56 -77 -22 34 -22 49 63 33 76 55 -40 72 62 -28 68 75 -92 -59 -91 -45 -45 7 39 -38 -49 50 42 71 72 64 -80 -68 -90 -87 32 77 12 91 60 45 44 -9 34 -52 43 -48 98 -96 72 28 -46 5 32 92 54 -44 -47 -5 -24 -45 15 11 -90 -98 67 2 92 80
97 7 53 22 59 15 31 22 -20 -61 49 4 -43 66 -47 4 -25 -82 -55 98 20 -13 -91 -19 52 99 26 3 -42 -90 -13 -24 -60 -62 -8 -7 42 97 20 -11 81 -10 27 -17 -23 0 -26 55 -46 67 31 41 -39 40 -59 -22 -88 86 44 -72 9 78 16 26 -83 -25 65 -63 67 6 -65 -23 47 -30 83 -88 13 -40 -4 -16 -8 -73 -87 -30 6

9
5 -5 1 8 -6 -8 4 -10 -7
-9 -8 -4 8 4 5 2 7 1
 */