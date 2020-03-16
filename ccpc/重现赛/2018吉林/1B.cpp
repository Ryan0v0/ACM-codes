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
        LL a=read(),b=read();
        LL ka=read(),kb=read();
        LL t1a=(sqrt(8*a+1)-1)/2;
        LL t1b=(sqrt(sqrt(8*a+8*b+1)-sqrt(1+8*a)))/2;
        //LL tb=(sqrt(8*a));
        while((1+t1a)*t1a/2<a) t1a++;
        while((t1a+1+t1a+t1b+1)*t1b/2<b) t1b++;
        LL t1=t1a+t1b;

        LL t2b=(sqrt(8*b+1)-1)/2;
        LL t2a=(sqrt(sqrt(8*b+8*a+1)-sqrt(1+8*b)))/2;
        //LL tb=(sqrt(8*a));
        while((1+t2b)*t2b<2*b) t2b++;
        while((t2b+1+t2b+t2a+1)*t2a<2*a) t2a++;
        LL t2=t2a+t2b;

        LL k1=t1a*ka+t1*kb;
        LL k2=t2*ka+t2b*kb;

        //cout<<t1<<' '<<t1a<<' '<<t1b<<' '<<k1<<endl;
        //cout<<t2<<' '<<t2b<<' '<<t2a<<' '<<k2<<endl;
        if(k1<k2){
            cout<<k1<<' ';
            F(i,1,t1a) cout<<"A";
            F(i,1,t1b) cout<<"B";
        }
        if(k1>k2){
            cout<<k2<<' ';
            F(i,1,t2b) cout<<"B";
            F(i,1,t2a) cout<<"A";
        }
        if(k1==k2) {
            if (t1 <= t2) {
                cout<<k1<<' ';
                F(i,1,t1a) cout<<"A";
                F(i,1,t1b) cout<<"B";
            }
            if (t1 > t2) {
                cout<<k2<<' ';
                F(i,1,t2b) cout<<"B";
                F(i,1,t2a) cout<<"A";
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
10
20 10 5 5
30 30 2 2
10 20 5 5

 */