//
// Created by 赵婉如 on 2019-07-23.
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
const int N=200010;
struct data{
    int val,id;
}a[N];
bool cmp(data a,data b){
    return a.val>b.val;
}
int main()
{
    int n=read();
    F(i,1,n){
        a[i].val=read();
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    int l,r;l=r=a[1].id;
    F(i,2,n){
        if(a[i].id==r+1){
            r++;
        }else if(a[i].id==l-1){
            l--;
        }else{
            puts("NO");
            return 0;
        }
    }
    //F(i,1,n) cout<<a[i].val<<endl;
    puts("YES");
    return 0;
}
/*
5
3 5 8 1 2
 */