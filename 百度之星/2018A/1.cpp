//
// Created by 赵婉如 on 2019-08-16.
// 10:45-
// 构成三角形的充要条件:任意两边大于第三边||任意两边小于第三边
// 直接贪心成立!（反证法,排序后只需最小边+次小边>最大边即可)
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
const int N=1010;
int n;
int a[N];
int ans;
int main()
{
    while(~scanf("%d",&n)){
        F(i,1,n) a[i]=read();ans=-1;
        //reverse(a+1,a+n+1);
        /*sort(a+1,a+n+1,greater<>());
        F(i,1,n) cout<<a[i]<<' ';cout<<endl;
        F(i,1,n) F(j,i+1,n){//a[i]<a[j]+a[k]==>找最小的k使得a[k]<a[i]-a[j]
            int k=upper_bound(a+1,a+n+1,a[i]-a[j],greater<>())-(a+1);
            if(k>j&&k<=n) {
                cout<<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
                ans=max(ans,a[i]+a[j]+a[k]);
            }
        }*/
        sort(a+1,a+n+1);
        F(i,1,n) F(j,i+1,n){//a[i]+a[j]>a[k],找最大的k使得
            int k=upper_bound(a+1,a+n+1,a[i]+a[j]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
3
1 1 100
7
1 9 9 90 2 2 4

 */