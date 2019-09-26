#include<bits/stdc++.h>
#define maxn 100010
#define linf (1ll<<60)
#define iinf 0x7fffffff
#define eps 1e-8
#define cl(x) memset(x,0,sizeof(x))
#define mod 998244353ll
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll read(ll x=0)
{
    ll c, f=1;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-f;
    for(;isdigit(c);c=getchar())x=x*10+c-48;
    return f*x;
}
struct BIT
{
    ll bit[maxn], n;
    void init(int N){n=N;for(int i=1;i<=n;i++)bit[i]=0;}
    ll lowbit(ll x){return x&(-x);}
    void add(ll pos, ll v)
    {
        for(;pos<=n;pos+=lowbit(pos))bit[pos]+=v;
    }
    ll sum(ll pos)
    {
        ll ans(0);
        for(;pos;pos-=lowbit(pos))ans+=bit[pos];
        return ans;
    }
}bit;
ll N;
vector<vector<ll>> v, h;
int main()
{
    ll x1, y1, x2, y2, i, j, l, r, ans(0);
    N=read();
    for(i=1;i<=N;i++)
    {
        x1=read()+5001, y1=read()+5001;
        x2=read()+5001, y2=read()+5001;
        if(x1==x2)v.emplace_back(vector<ll>{x1,min(y1,y2),max(y1,y2)});
        else h.emplace_back(vector<ll>{y1,min(x1,x2),max(x1,x2)});
    }
    sort(h.begin(),h.end(),[](vector<ll>& a, vector<ll>& b)->bool{return a.at(0)<b.at(0);});
    sort(v.begin(),v.end(),[](vector<ll>& a, vector<ll>& b)->bool{return a.at(2)>b.at(2);});
    for(i=0;i<h.size();i++)
    {
        bit.init(10010);
        vector<vector<ll>> lis;
        for(auto x:v)
            if(x.at(0)>=h[i].at(1) and x.at(0)<=h[i].at(2) and x.at(1)<=h[i].at(0))
            {
                lis.emplace_back(x);
                bit.add(x.at(0),+1);
            }
        for(j=i+1;j<h.size();j++)
        {
            while(!lis.empty() and lis.back().at(2)<h[j].at(0))
            {
                bit.add(lis.back().at(0),-1);
                lis.pop_back();
            }
            auto l=max(h[i].at(1),h[j].at(1)), r=min(h[i].at(2),h[j].at(2));
            if(l>=r)continue;
            auto t=bit.sum(r)-bit.sum(l-1);
            ans+=t*(t-1)/2;
        }
    }
    cout<<ans;
    return 0;
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/
vector<vector<ll>> h;
h.emplace_back(vector<ll>{y1,min(x1,x2),max(x1,x2)});
sort(h.begin(),h.end(),[](vector<ll>& a, vector<ll>& b)->bool{return a.at(0)<b.at(0);});