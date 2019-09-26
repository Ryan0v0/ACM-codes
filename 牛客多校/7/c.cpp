//
// Created by 赵婉如 on 2019-08-08.
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
const int N=100010;
int n;
LL h[N],c[N],p[N];
struct node{
    LL h,c,p;
    int id;
    bool operator <(const node &x)const{
        return c<x.c;
    }
}a[N];
set<node> s;
//set<node> iterator::it;
bool cmp(node x,node y)
{
    return x.h<y.h;
}
int main()
{
    while(~scanf("%d",&n)){
        F(i,1,n){
            a[i].h=read();
            a[i].c=read();
            a[i].p=read();
            a[i].id=read();
        }
        s.clear();
        sort(a+1,a+n+1,cmp);
        F(i,1,n){
            s.insert(a[i]);
            //sum[1~p[i]]
            auto it=s.begin();
            //int mxid=(*it).id;
            node mx=(*it);
            while() {
                if (a[].p) {

                }
            }
        }
    }
    return 0;
}