//
// Created by 赵婉如 on 2019-08-07.
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
const int N=200010;
int q2[N];
int mx[N];
int pos[N],val[N];
int main()
{
    int n=read();
    F(i,1,n) val[i]=read();
    int q=read();//id=-1;
    mec(pos,0);
    F(i,1,q){
        int opt=read();
        if(opt==1){
            int p=read();int x=read();
            pos[p]=i;val[p]=x;
        }
        else if(opt==2){
            q2[i]=read();
            //id=i;
            //mx=max(mx,x);
        }
    }
    mx[q]=q2[q];
    D(i,q-1,0) mx[i]=max(mx[i+1],q2[i]);
    //cout<<id<<' '<<mx<<endl;
    //F(i,1,n) cout<<pos[i]<<' '<<val[i]<<endl;
    F(i,1,n){
        cout<<max(val[i],mx[pos[i]])<<' ';/*
        if(pos[i]<id){
            cout<<mx<<' ';
        }else if(pos[i]>id){
            cout<<val[i]<<' ';
        }*/
    }
    return 0;
}