//
// Created by 赵婉如 on 2020-02-15.
//

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
char str[200];
int n,ans,len;
int cal(int x){
    int sum=0,cnt=0;
    for(int i=0;i<n;i++){
        //if(1&(x>>i)) cout<<str[i+1];
    //for(int i=n;i>=1;i--){
        if(1&(x>>i)){
            //cout<<str[i];
            if(str[i+1]=='I') sum++,cnt++;
            else if(str[i+1]=='O') sum--;
            else {
                //cout<<endl;
                return -1;
            }
            if(sum<0) {
                //cout<<endl;
                return -1;
            }
        }
    }
    if(sum!=0) return -1;
    // cout<<endl;
    for(int i=0;i<n;i++){
        if(!(1&(x>>i))){
            if(str[i+1]=='I'||str[i+1]=='i') sum++;
            else if(str[i+1]=='O'||str[i+1]=='o') sum--;
            if(sum<0) return -1;
        }
    }
    if(sum!=0) return -1;
    return cnt;
}
void solve()
{
    scanf("%s",str+1);
    n=strlen(str+1);ans=0;
    //cout<<"n="<<n<<endl;
    for(int i=0;i<(1<<n);i++){
        int res=cal(i);
        if(res!=-1&&res>ans){
            ans=res;
            //for(int j=0;j<n;j++)
            //    if(1&(i>>j)) cout<<str[j+1];cout<<endl;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int tt=read();
    F(Case,1,tt) {
        cout << "Case #" << Case << ": ";
        solve();
    }
    return 0;
}
