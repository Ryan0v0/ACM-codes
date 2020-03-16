//
// Created by 赵婉如 on 2019-08-23.
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
    int q=rand()%50+1;cout<<q<<endl;
    while(q--){
        int opt=rand()%2+1;int x=rand()%50000+1;
        cout<<opt<<' '<<x<<' ';
        if(opt==1) cout<<rand()%200-100<<endl;
        else if(opt==2) cout<<rand()%x<<endl;
    }
    return 0;
}
