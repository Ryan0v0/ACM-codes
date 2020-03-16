//
// Created by 赵婉如 on 2019-10-03.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
int main() {
    ios::sync_with_stdio(false);
    int _,ca=0;cin>>_;
    while(_--) {
        cin>>n>>m>>k;
        ll ans = (k-1)%(n-m+1)+1;
        if(k==1) ans = m;
        else if(k >= m) {
            for(ll i=2;i<=m;i++)
                ans = (ans + k -1)%(i+n-m)+1;
        }
        else {
            ll now = 1;ll a = n-m;
            while(now < m) {
                ll d = (ll)ceil((now + a - ans)*1.0/(k-1));
                if(d == 0) d++;
                if(now+d >= m) {   d = m-now;}
                now +=d;ll mod = (now+a);
                ans = (ans + k*d%mod-1+mod)%mod+1;
            }
        }
        cout<<"Case #"<<++ca<<": "<<ans<<endl;
    }
}