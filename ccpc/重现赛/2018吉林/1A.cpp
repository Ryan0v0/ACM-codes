//
// Created by 赵婉如 on 2019-10-02.
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
int main()
{
    int tt=read();
    while(tt--){
        int a=read();int b=read();int c=read();int d=read();
        int cnt=(a>0)+(b>0)+(c>0)+(d>0);
        switch(cnt){
            case 0:
                puts("Typically Otaku");
                break;
            case 1:
                puts("Eye-opener");
                break;
            case 2:
                puts("Young Traveller");
                break;
            case 3:
                puts("Excellent Traveller");
                break;
            case 4:
                puts("Contemporary Xu Xiake");
                break;
        }
    }
    return 0;
}