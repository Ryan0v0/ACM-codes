//
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
LL n;
LL sol2(LL x)
{
    return (x / 6 - 1) * 3 + 4;
}
LL sol0(LL x)
{
    return x/6*3;
}
LL foo(){
    //why
    //should
    //my
    //code

}
int main()
{
    int tt=read();
    while(tt--){
        n=read();
        if(n%6==3||n%6==5){
            cout<<n/6<<endl;
        }else if(n%6==0){
            cout<<sol0(n)<<endl;
        }else if(n%6==2) {
            cout <<sol2(n)<< endl;
        }else if(n%6==1){
            cout<<((n+1)/6-1)*3+4+(n+2)/6<<endl;
        }else if(n%6==4){
            cout<<sol2(n-2)+sol0(n+2)-1<<endl;
        }
    }
    return 0;
}