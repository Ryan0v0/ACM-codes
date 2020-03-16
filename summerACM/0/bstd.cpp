//
// Created by 赵婉如 on 2019-08-31.
//

#include<cstdio>
#include<string>
using namespace std;
using LL=long long;

int T;
LL a,b,c,d,v;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        string ans;
        if(a==c&&b==d)
        {
            puts("Yes\n");
            continue;
        }
        if(a==b||abs((d-c))%abs((b-a))!=0||abs((c+d)-(a+b))%abs(b-a)!=0)
        {
            puts("No");
            continue;
        }
        v=((c+d)-(a+b))/(b-a);
        LL tmp=(d-c)/(b-a);
        if(tmp<0||__builtin_popcountll(tmp)!=1)
        {
            puts("No");
            continue;
        }
        int pos=0;
        LL cur=0;
        while(!(tmp>>pos&1))
            pos++;
        for(int i=pos-1;i>=0;i--)
            if(cur<v)
                ans='A'+ans,cur+=1LL<<i;
            else
                ans='B'+ans,cur-=1LL<<i;
        if(cur==v)
        {
            puts("Yes");
            puts(ans.c_str());
        }
        else
            puts("No");
    }
    return 0;
}