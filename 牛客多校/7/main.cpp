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
const int N=64;
//int a[N];
vector<int> a,b,c;
//int solve(int *a)
LL xx,yy,ans;
int main()
{
    //cout<<((1<<31)-1)<<endl;
    int tt=read();
    while(tt--){
        LL x=read();LL y=read();
        a.clear();b.clear();c.clear();
        while(x){
            a.push_back(x%10);
            x/=10;
        }
        //cout<<a.size()<<' ';
        xx=0LL;
        F(i,0,a.size()-1) xx=xx*10LL+a[i];//cout<<endl;
        while(y) {
            b.push_back(y % 10);
            y /= 10;
        }
        //cout<<b.size()<<endl;
        yy=0LL;
        F(i,0,b.size()-1) yy=yy*10LL+b[i];//cout<<endl;
        ans=xx+yy;
        //cout<<"ans="<<ans<<endl;
        while(ans) {
            c.push_back(ans % 10);
            ans /= 10;
        }
        int flag=0;
        F(i,0,c.size()-1){
            if(c[i]!=0) flag=1;
            if(c[i]!=0 ||(c[i]==0&&flag)) cout<<c[i];//cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
/*
10
12 1
101 9
991 1
2147483647 2147483647
2000000000 99
1111 1010
9 1

*/