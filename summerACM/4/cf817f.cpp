#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const long long N=150020;
map<long long,long long> mp;
long long b[N*4],n,m,cnt; 
struct ask{
    long long l,r;
    long long k;
}q[N];
struct tree{
    long long l,r,sum,sev,lazy;
}tr[N*40];
void build(long long l,long long r,long long now){
    tr[now].l=l;
    tr[now].r=r;
    tr[now].lazy=-1;
    if(l==r)return;
    long long mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
}
void pushdown(long long now){
    long long mid=(tr[now].l+tr[now].r)>>1;
    if(tr[now].lazy!=-1){
        tr[now*2].lazy=tr[now*2+1].lazy=tr[now].lazy;
        tr[now*2].sum=(mid-tr[now].l+1)*tr[now].lazy;
        tr[now*2+1].sum=(tr[now].r-mid)*tr[now].lazy;
        tr[now*2].sev=tr[now*2+1].sev=0;
        tr[now].lazy=-1; 
    }
    if(tr[now].sev){
        tr[now*2].sev^=1;
        tr[now*2+1].sev^=1;
        tr[now*2].sum=(mid-tr[now].l+1)-tr[now*2].sum;
        tr[now*2+1].sum=(tr[now].r-mid)-tr[now*2+1].sum;
        tr[now].sev=0;
    }
}
void update(long long l,long long r,long long now,long long k){
//    cout<<l<<" "<<r<<" "<<tr[now].l<<" "<<tr[now].r<<" "<<now<<endl;
    pushdown(now);
    if(tr[now].l==l&&tr[now].r==r){
        tr[now].sum=(tr[now].r-tr[now].l+1)*k;
        tr[now].lazy=k;
        tr[now].sev=0;
        return ;
    }
    long long mid=(tr[now].l+tr[now].r)>>1;
    if(l>mid){
        update(l,r,now*2+1,k);
    }
    else if(r<=mid){
        update(l,r,now*2,k);
    }
    else{
        update(l,mid,now*2,k);
        update(mid+1,r,now*2+1,k);
    }
    tr[now].sum=tr[now*2].sum+tr[now*2+1].sum;
}
void serve(long long l,long long r,long long now){
    pushdown(now);
    if(tr[now].l==l&&tr[now].r==r){
        tr[now].sum=(tr[now].r-tr[now].l+1)-tr[now].sum;
        tr[now].sev^=1;
        return;
    }
    long long mid=(tr[now].l+tr[now].r)>>1;
    if(l>mid)serve(l,r,now*2+1);
    else if(r<=mid)serve(l,r,now*2);
    else{
        serve(l,mid,now*2);
        serve(mid+1,r,now*2+1);
    }
    tr[now].sum=tr[now*2].sum+tr[now*2+1].sum;
}
void check(long long now){
    if(tr[now].l==tr[now].r){
        printf("%lld\n",b[tr[now].l]);
        return ;
    }
    long long mid=(tr[now].l+tr[now].r)>>1;
    pushdown(now);
    if(tr[now*2].sum<mid-tr[now].l+1)check(now*2);
    else return check(now*2+1);
}
int main(){
    scanf("%lld",&m);
    for(long long i=1;i<=m;i++){
        scanf("%lld%lld%lld",&q[i].k,&q[i].l,&q[i].r);
        q[i].r++;
        b[++cnt]=q[i].l;
        b[++cnt]=q[i].r;
    }
    b[++cnt]=1;
    sort(b+1,b+1+cnt);
    n=unique(b+1,b+1+cnt)-(b+1);
    for(long long i=1;i<=n;i++){
        mp[b[i]]=i;
    }
    build(1,n,1);
    for(long long i=1;i<=m;i++){
        if(q[i].k==1){
            update(mp[q[i].l],mp[q[i].r]-1,1,1);
        }
        else if(q[i].k==2){
            update(mp[q[i].l],mp[q[i].r]-1,1,0);
        }
        else{
            serve(mp[q[i].l],mp[q[i].r]-1,1);
        }
        check(1);
    }
    return 0;
}
