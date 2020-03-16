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
const int N=1e5+10;
LL sum[N];
int main()
{
    F(i,1,N) sum[i]=sum[i-1]+i;
    //前缀和
    int tt=read();
    while(tt--){
        LL a=read(),b=read();
        LL ka=read(),kb=read();
        LL t=lower_bound(sum+1,sum+N,a+b)-sum;
        string str;
        string str1;
        //先打A
        LL ta=lower_bound(sum+1,sum+N,a)-sum;
        LL los=sum[ta]-a;
        LL s1=1LL*ta*ka+1LL*t*kb;
        if(sum[t]-sum[ta]>=b)
            F(i,1,ta) str+='A';
        else{
            F(i,1,ta){
                if(i!=los) str+='A';
                else str+='B';
            }
        }
        F(i,ta+1,t) str+='B';
        //先打B
        LL tb=lower_bound(sum+1,sum+N,b)-sum;
        LL s2=1LL*t*ka+1LL*tb*kb;
        LL locb=sum[tb]-b;
        LL lb1=upper_bound(sum+1,sum+N,locb)-(sum+1);
        LL bac=sum[t]-sum[tb];
        if(bac+sum[lb1]>=a) {
            F(i,1,lb1) str1+='A';
            F(i,lb1+1,tb) str1+='B';
            F(i,tb+1,t) str1+='A';
        }else {
            LL left=a-bac;
            F(i,1,tb){
                if(left-i>i||left==i){
                    left-=i;
                    str1+='A';
                }else str1+='B';
            }
            F(i,tb+1,t) str1+='A';
        }
        if(s1>s2){
            cout<<s2<<' ';
            cout<<str1<<endl;
        }else if(s1<s2){
            cout<<s1<<' ';
            cout<<str<<endl;
        }else if(str<str1){
            cout<<s1<<' ';
            cout<<str<<endl;
        }else{
            cout<<s2<<' ';
            cout<<str1<<endl;
        }
    }
}
/*
5
5 15 5 25
5 15 25 5
20 10 5 5
30 30 2 2
10 20 5 5

 */