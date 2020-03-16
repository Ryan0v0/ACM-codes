//
// Created by 赵婉如 on 2019-10-09.
//

#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
const int N=2e5+10;
int h,n;
int x[N];
set<int> s;
int main()
{
    int tt=read();
    while(tt--){
        h=read();n=read();
        s.clear();
        F(i,1,n){
            //x[i]=read();
            int x=read();
            s.insert(x);
        }
        int cur=h;int cnt=0;
        s.insert(h-1);
        while(cur>1){
            if(s.count(cur-1)){
                if(!s.count(cur-2)){
                    cnt++;
                    cout<<"!!!"<<cur-2<<endl;
                    s.insert(cur-2);
                }
                cur=cur-2;
            }else{
                auto it=s.find(cur);
                if(it==s.begin()){
                    cur=0;
                }else{
                    it--;
                    cur=*it;
                }
            }
            if(s.count(cur-1)) s.erase(cur-1);
            else s.insert(cur-1);
            //s.insert(cur-1);
            cout<<"cur="<<cur<<' '<<s.count(cur-1)<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}