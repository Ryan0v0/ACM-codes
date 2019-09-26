//
// Created by 赵婉如 on 2019-07-14.
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
char s[200],t[200],p[200];
int a[50],b[50],c[50];
int main()
{
    int q=read();
    while(q--){
        mec(a,0);mec(b,0);mec(c,0);
        scanf("%s",s);
        scanf("%s",t);
        scanf("%s",p);
        F(i,0,strlen(s)-1) a[s[i]-'a']++;
        F(i,0,strlen(t)-1) b[t[i]-'a']++;
        F(i,0,strlen(p)-1) c[p[i]-'a']++;
        int r=0;
        bool flag=true;
        for(int l=0;l<strlen(s);l++){
            while(s[l]!=t[r] && r<strlen(t)) r++;
            if(r==strlen(t)){
                flag=false;
                break;
            }
            r++;//!!
        }
        if(!flag){
            puts("NO");continue;
        }
        F(i,0,25){
            if(b[i]-a[i]>c[i]){
                flag=false;
                break;
            }
        }
        if(!flag){
            puts("NO");continue;
        }
        puts("Yes");
    }
    return 0;
}