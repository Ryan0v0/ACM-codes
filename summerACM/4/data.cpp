//
// Created by 赵婉如 on 2019-08-14.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
	freopen("evaluations.in","w",stdout);
    srand(time(NULL));
    int tt=rand()%100+1;
    cout<<tt<<endl;
    while(tt--) {
        int n=rand()%(int)1e5+1;
        cout << n << endl;
        F(i, 2, n) {
            cout<<i<<' ';
            cout<<rand()%(i-1)+1<<' ';
            cout<<rand()%(int)1e5+1<<endl;
        }
    }
    return 0;
}
