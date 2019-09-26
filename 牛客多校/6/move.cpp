//
// Created by 赵婉如 on 2019-08-03.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
int sum[N<<2],v[N],n,k;
int buk[N];
void update(int p,int l,int r,int a,int b)
{
    if(l==r)
    {
        sum[p] = b;
        return ;
    }
    int mid = (l+r)>>1;
    if(a<=mid)update(p<<1,l,mid,a,b);
    else update(p<<1|1,mid+1,r,a,b);
    sum[p] = max(sum[p<<1],sum[p<<1|1]);
}
int find(int p,int l,int r,int a,int b)
{
    if(l>=a&&r<=b)
        return sum[p];
    int mid = (l+r)>>1;
    int ans = -1;
    if(a<=mid)ans = max(ans,find(p<<1,l,mid,a,b));
    if(b >mid)ans = max(ans,find(p<<1|1,mid+1,r,a,b));
    return ans;
}
bool check(int vol)
{
    memset(sum,-1,sizeof(sum));
    memset(buk,0,sizeof(buk));
    for(int i = 1;i<= n;i++)
    {
        //update(1,1,1000,v[i],v[i]);
        buk[v[i]]++;
    }
    int cnt = 0;
    for(int i = 1;i<= k;i++)
    {
        int tmpv = vol,tmp;
        bool flag = true;
        while(flag&&tmpv)
        {
            flag = false;
            for(int i = tmpv;i>= 1;i--)
                if(buk[i])
                {
                    flag = true;
                    tmpv-=i;
                    buk[i]--;
                    cnt++;
                    break;
                }
        }
    }
    return cnt>=n;
}
int main()
{
    int cas;
    int c = 1;
    scanf("%d",&cas);
    while(c<=cas)
    {
        scanf("%d%d",&n,&k);
        int mxv = 0,Sum = 0;
        for(int i = 1;i<= n;i++)
        {
            scanf("%d",&v[i]);
            mxv = max(mxv,v[i]);
            Sum+=v[i];
        }
        int l = mxv,r = Sum+1;
        for(int i = l;i< r;i++)
            if(check(i))
            {
                l = i;
                break;
            }
        printf("Case #%d: %d\n",c,l);
        c++;
    }
    return 0;
}