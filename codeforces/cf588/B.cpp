//
// Created by 赵婉如 on 2019-09-23.
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
const int N=2e5+10;
char str[N];
int s[N];
int ans[N];
int cnt;
int main()
{
    int n=read();int m=read();
    scanf("%s",str+1);
    F(i,1,n) s[i]=str[i]-'0';
    if(n==1){
        if(m==1) cout<<0;
        else cout<<s[1];
        return 0;
    }
    if(m==0){
        F(i,1,n) cout<<s[i];
        return 0;
    }
    if(s[1]>1) ans[1]=1,cnt++;
    else ans[1]=s[1];
    F(i,2,n){
        if(s[i]>0&&cnt<m) ans[i]=0,cnt++;
        else{
            if(s[i]==0) ans[i]=0;
            if(cnt==m) ans[i]=s[i];
        }
    }
    F(i,1,n) cout<<ans[i];
    return 0;
}