//
// Created by 赵婉如 on 2019-09-23.
//

#include <bits/stdc++.h>
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
const int N=1e4;
LL a[N],b[N];
//vector<int> v;
set<int> s;
LL ans;
bool flag;
int main()
{
    int n=read();
    F(i,1,n) a[i]=read();
    F(i,1,n) b[i]=read();
    s.clear();
    F(i,1,n) s.insert(i);
    //F(i,0,(LL)s.size()-1){
    do{
        flag=0;
        for (int i:s) {
            int cnt = 0;
            LL x = a[i];
            //F(j,0,(LL)v.size()-1){
            for (int j:s) {
                LL y = a[j];
                if ((x & y) < x) cnt++;
            }
            //cout << i << ' ' << x << ' ' << cnt << ' ' << (LL) s.size() - 1 << endl;
            if (cnt == (int)s.size() - 1){
                s.erase(i),flag=1;
                break;
            }
        }
        //cout<<"~~~~"<<endl;
    }while(flag);
    for(int i:s){
        ans+=b[i];
    }
    cout<<ans<<endl;
    return 0;
}