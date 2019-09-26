//
// Created by 赵婉如 on 2019-08-08.
//

#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define INF 1000000000
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
    srand(time(NULL));
    int n=rand()%100000+1;
    cout<<n<<endl;
    F(i,1,n){
        //h[i]=rand();
        //c[i]=rand();
        int x=rand()%INF+1;
        int y=rand()%200+1;
        int p=rand()%INF+1;
        cout<<x<<' '<<y<<' '<<p<<endl;
    }
    return 0;
}
/*
2
5 1 1
1 10 1
2
5 1 2
3 2 3

 */