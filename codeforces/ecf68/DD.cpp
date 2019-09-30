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

int eq[50][5],cnt[15],mx[15],ans;
int num;
void init()
{
    F(i,1,9) for(int j=i;i+j<=9;j++){
        eq[++num][0]=i;mx[i]++;
        eq[num][1]=j;mx[j]++;
        eq[num][2]=i+j;mx[i+j]++;
    }
}/*
void dfs(int x,int res)
{
    if(x>36) return;
    cnt[x][0]--;cnt[x][1]--;cnt[x][2]--;
    if(cnt[x][0]>=0 && cnt[x][1]>=0 && cnt[x][2]>=0) {
        ans=max(ans,res+1);
        dfs(x+1,res+1);
    }
    cnt[x][0]++;cnt[x][1]++;cnt[x][2]++;
    dfs(x+1,res);
}*//*
void dfs(int x,int res)
{
    //cout<<x<<' '<<ans<<endl;
    if(x>20) return;
    cnt[eq[x][0]]--;cnt[eq[x][1]]--;cnt[eq[x][2]]--;
    //cout<<cnt[eq[x][0]]<<' '<<cnt[eq[x][1]]<<' '<<cnt[eq[x][2]]<<endl;
    //cout<<"!!"<<eq[x][0]<<' '<<eq[x][1]<<' '<<eq[x][2]<<endl;

    if(cnt[eq[x][0]]>=0 && cnt[eq[x][1]]>=0 && cnt[eq[x][2]]>=0) {
        //cout<<"!!!!"<<endl;
        cout<<cnt[eq[x][0]]<<' '<<cnt[eq[x][1]]<<' '<<cnt[eq[x][2]]<<endl;
        cout<<"!!"<<eq[x][0]<<' '<<eq[x][1]<<' '<<eq[x][2]<<endl;
        if(eq[x][0]!=eq[x][1]) ans=max(ans,res+2),dfs(x+1,res+2);
        else ans=max(ans,res+1),dfs(x+1,res+1);
    }
    cnt[eq[x][0]]++;cnt[eq[x][1]]++;cnt[eq[x][2]]++;
    dfs(x+1,res);
}*/
void dfs(int x,int res)
{
    //cout<<x<<' '<<ans<<endl;
    if(x>20) return;
    cnt[eq[x][0]]--;cnt[eq[x][1]]--;cnt[eq[x][2]]--;
    //cout<<cnt[eq[x][0]]<<' '<<cnt[eq[x][1]]<<' '<<cnt[eq[x][2]]<<endl;
    //cout<<"!!"<<eq[x][0]<<' '<<eq[x][1]<<' '<<eq[x][2]<<endl;
    if(cnt[eq[x][0]]>=0 && cnt[eq[x][1]]>=0 && cnt[eq[x][2]]>=0) {
        //cout<<"!!!!"<<endl;
        //cout<<cnt[eq[x][0]]<<' '<<cnt[eq[x][1]]<<' '<<cnt[eq[x][2]]<<endl;
        //cout<<"!!"<<eq[x][0]<<' '<<eq[x][1]<<' '<<eq[x][2]<<endl;
        if(eq[x][0]!=eq[x][1]){
            cnt[eq[x][0]]--;cnt[eq[x][1]]--;cnt[eq[x][2]]--;
            if(cnt[eq[x][0]]>=0 && cnt[eq[x][1]]>=0 && cnt[eq[x][2]]>=0) {
                ans=max(ans,res+2),dfs(x+1,res+2);
            }
            cnt[eq[x][0]]++;cnt[eq[x][1]]++;cnt[eq[x][2]]++;
            //ans=max(ans,res+1),dfs(x+1,res+1);
        }
        ans=max(ans,res+1),dfs(x+1,res+1);
    }
    cnt[eq[x][0]]++;cnt[eq[x][1]]++;cnt[eq[x][2]]++;
    dfs(x+1,res);
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
        //else{
            ans=0;
            dfs(1,0);
            cout<<ans<<endl;
        //}
    }
    return 0;
}
/*
10
1 1 1 1 1 1 1 1 1
2 2 2 2 2 2 2 2 2
0 3 3 0 3 0 0 0 0
100 100 100 100 100 100 100 100 100
8 8 8 8 8 8 8 8 8

*/