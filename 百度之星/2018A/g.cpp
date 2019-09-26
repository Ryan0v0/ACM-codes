//
// Created by 赵婉如 on 2019-08-18.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
LL x10,x2,x3,x4;
LL y10,y2,y3,y4;
LL w,h;
int main()
{
    freopen("grave.in","r",stdin);
    freopen("grave.out","w",stdout);
    scanf("%id%lld%lld%lld",&x10,&y10,&x2,&y2);
    scanf("%lld%lld%lld%lld",&x3,&y3,&x4,&y4);
    int w1=x2-x10;int h1=max(y3-y10,y2-y4);
    int w2=max(x3-x10,x2-x4);int h2=y2-y10;
    scanf("%lld%lld",&w,&h);
    if((w<=w1&&h<=h1)||(w<=w2&&h<=h2)){
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}
/*
-1000000000 -1000000000 1000000000 1000000000
-1 -1 1 1
1000000000 1000000000

 */