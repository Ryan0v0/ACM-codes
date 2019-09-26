//
// Created by 赵婉如 on 2019-08-24.
//
#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=1e6+10;
int n;
int a[N];
char s[N];
void solve()
{
    n=read();mec(a,0);
    scanf("%s",s+1);
    F(i,1,n) a[i]=s[i]-'0';
    int half=(n+1)/2;
    int best=0,window=0;
    F(i,1,n){
        window+=a[i];
        if(i>half) window-=a[i-half];
        best=max(best,window);
    }
    cout<<best<<endl;
}
int main()
{
    int tt=read();
    F(Case,1,tt) {
        cout << "Case #" << Case << ": ";
        solve();
    }
    return 0;
}