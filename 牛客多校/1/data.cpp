//
// Created by 赵婉如 on 2019-08-25.
//

//
// Created by 赵婉如 on 2019-08-24.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 1000000000000000000
#define pa pair<LL,int>
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
    int tt=rand()%10+1;cout<<tt<<endl;
    int n,m;
    F(i,1,tt){
        do{
            m=rand()%1000000000+1;n=m-rand()%100000;
        }while(n<1);
	//n=rand()%20+1;m=n+rand()%20;
        cout<<n<<' '<<m<<endl;
    }
    return 0;
}
