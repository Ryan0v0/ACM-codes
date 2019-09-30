//
// Created by 赵婉如 on 2019-09-28.
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
char s[200];
int main()
{
    int t;
    int kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int n=strlen(s);
        LL output=-1000000000000000000;
        for(int i=2;i<n-2;i++) {
            LL a=0;
            for(int j=0;j<i-1;j++) a=a*10+s[j]-'0';
            LL b=s[i-1]-'0';
            LL tmp=a+b;
            a=0;b=0;
            for(int j=1;j<i;j++) a=a*10+s[j]-'0';
            b=s[0]-'0';
            LL tmp2=a+b;
            LL c=s[i]-'0';
            LL d=s[i+1]-'0';
            LL e=0;
            for(int j=i+2;j<n;j++) e=e*10+s[j]-'0';
            output=max(output,max(tmp,tmp2)-c*d/e);
        }
        printf("Case #%d: ",++kase);
        printf("%I64d\n",output);
    }
}