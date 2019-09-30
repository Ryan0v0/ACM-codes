//
// Created by 赵婉如 on 2019-09-27.
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
int cnt[10], eq[40][3], mx[12], ans;
void init()
{
    int num = 0;
    F(i,1,9) for(int j = 1; j +i <= 9; j++) {
            eq[num][0] = i;
            eq[num][1] = j;
            eq[num++][2] = i+j;
            mx[i]++;mx[j]++;mx[i+j]++;
        }
}
void add(int x, int val)
{
    cnt[eq[x][0]] += val;
    cnt[eq[x][1]] += val;
    cnt[eq[x][2]] += val;
}
void dfs(int x, int res)
{
    if(36 - x + res <= ans || x == 36) return ;
    add(x, -1);
    if(cnt[eq[x][0]] >= 0 && cnt[eq[x][1]] >= 0 && cnt[eq[x][2]] >= 0){
        ans = max(ans, res+1);
        dfs(x+1, res+1);
    }
    add(x, 1);
    dfs(x+1, res);
}
int main()
{
    int tt=read();
    init();
    F(Case,1,tt){
        cout<<"Case #"<<Case<<": ";
        bool ismx=true;
        F(i,1,9){
            cnt[i]=read();
            cnt[i]=min(cnt[i],mx[i]);
            if(cnt[i]<mx[i]) ismx=false;
        }
        //F(i,1,9) cout<<mx[i]<<' ';cout<<endl;
        if(ismx) cout<<36<<endl;
        else{
            ans=0;
            dfs(0,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}
/*
100
1 1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2 2
0 3 3 0 3 0 0 0 0
3 2 1 0 0 0 0 0 0

 */