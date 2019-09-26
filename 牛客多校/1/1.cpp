//
// Created by 赵婉如 on 2019-08-18.
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
int calc(int x)
{
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}
vector<int> v;
int main()
{
    int tt=read();
    while(tt--){
        v.clear();
        int n=read();
        //cout<<calc(n)<<endl;
        int m=calc(n);
        F(i,1,m){
            if(m%i==0&&n%i==0){
                v.push_back(i);
                //cout<<i<<endl;
            }
        }
        cout<<v.size()<<endl;
        F(i,0,v.size()-1){
            if(i==v.size()-1) cout<<v[i]<<endl;
            else cout<<v[i]<<' ';//cout<<v[v.size()-1]<<endl;
        }
    }
    return 0;
}
/*
3
1
9
666666

 */