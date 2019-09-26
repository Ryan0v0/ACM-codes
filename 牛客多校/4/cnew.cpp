//
// Created by 赵婉如 on 2019-07-27.
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
#define eps (1e-8)
#define MAX 0x3f3f3f3f
#define u_max 1844674407370955161
#define l_max 9223372036854775807
#define i_max 2147483647
#define re register
#define pushup() tree[rt]=max(tree[rt<<1],tree[rt<<1|1])
#define nth(k,n) nth_element(a,a+k,a+n);  // 将 第K大的放在k位
#define ko() for(int i=2;i<=n;i++) s=(s+k)%i // 约瑟夫
#define ok() v.erase(unique(v.begin(),v.end()),v.end()) // 排序,离散化
using namespace std;

typedef long long ll;
const double pi = atan(1.)*4.;
const int M=1e3+5;
const int N=1e6+5;
int n;
ll a[N],p1=1,p2=1,p3=1,p4=1,x=0,y=0;
ll ans1=-l_max,ans2=l_max;
ll tree[N<<2];
ll sum[N];
int l[N],r[N];

void sett(int l,int r,int rt){      // 最小值线段树
    if(l==r){
        tree[rt]=a[l];
        return ;
    }
    int mid=l+r>>1;
    sett(l,mid,rt<<1);
    sett(mid+1,r,rt<<1|1);
    tree[rt]=min(tree[rt<<1],tree[rt<<1|1]);
}


ll findd(int a,int b,int l,int r,int rt){
    if(a<=l&&b>=r){
        return tree[rt];
    }
    int mid=l+r>>1;
    ll ans=l_max;
    if(a<=mid)
        ans=min(ans,findd(a,b,l,mid,rt<<1));
    if(b>mid)
        ans=min(ans,findd(a,b,mid+1,r,rt<<1|1));
    return ans;
}
struct fun{
    int l,r;
}f[N],g[N];          // f 保存最大子段和相同的区间， g 保存最小子段和相同的区间
void fun1(){         //  求最大子段和
    ll sum=0;
    int d=1;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum>ans1){
            ans1=sum;
            p1=d;
            p2=i;
        }
        if(sum<0){
            sum=0;
            d=i+1;
        }
    }
    d=1; sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum==ans1){
            p1=d;
            p2=i;
            f[x].l=p1;
            f[x++].r=p2;
        }
        if(sum<0){
            sum=0;
            d=i+1;
        }
    }
}

void fun2(){          // 求最小子段和
    ll sum=0;
    int d=1;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum<ans2){
            ans2=sum;
            p3=d;
            p4=i;
        }
        if(sum>=0){
            sum=0;
            d=i+1;
        }
    }

    d=1; sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        //printf("sum == %lld\n",sum);
        if(sum==ans2){
            //  printf("YES\n");
            p3=d;
            p4=i;
            g[y].l=p3;
            g[y++].r=p4;
        }
        if(sum>=0){
            sum=0;
            d=i+1;
        }
    }
}
stack<int>s1,s2;
int main() {
    scanf("%d", &n);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {          // 左边第一个比它小的
        while (s1.size() && a[s1.top()] >= a[i]) s1.pop();
        if (s1.empty()) l[i] = 0;
        else l[i] = s1.top();
        s1.push(i);
    }

    for (int i = n; i >= 1; i--) {          // 右边第一个比它小的
        while (s2.size() && a[s2.top()] >= a[i]) s2.pop();
        if (s2.empty()) r[i] = n + 1;
        else r[i] = s2.top();
        s2.push(i);
    }

    ll ans = -1 * 1e9;
    for (int i = 1; i <= n; i++) {
        ll cut = a[i] * (sum[r[i] - 1] - sum[l[i]]);
        ans = max(ans, cut);
    }

    fun1();
    fun2();

    sett(1, n, 1);
    ll cut1 = -l_max, cut2 = l_max;
    for (int i = 0; i < x; i++) {
        cut1 = max(cut1, findd(f[i].l, f[i].r, 1, n, 1));
    }
    for (int i = 0; i < y; i++) {
        cut2 = min(cut2, findd(g[i].l, g[i].r, 1, n, 1));
    }
    printf("%lld\n", max(ans, max(cut1 * ans1, cut2 * ans2)));
    return 0;
}