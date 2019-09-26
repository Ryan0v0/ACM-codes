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
    int q=read();
    while(q--) {
        int x1=-100000,x2=100000;
        int y1=100000,y2=-100000;
        int n=read();
        F(i,1,n){
            int x=read();
            int y=read();
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a==0){
                x1=max(x1,x);
            }
            if(b==0){
                y1=min(y1,y);
            }
            if(c==0){
                x2=min(x2,x);
            }
            if(d==0){
                y2=max(y2,y);
            }
        }
        if(x1<=x2 && y1>=y2){
            cout<<1<<' '<<x1<<' '<<y1<<endl;
        }else{
            puts("0");
        }
    }
    return 0;
}
