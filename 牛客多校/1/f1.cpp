//
// Created by 赵婉如 on 2019-08-24.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
int ans,len;
unordered_set<string> s;/*
string GetSig(const string& a,int st,int ed)
{
    string sub=a.substr(st,ed-st);
    sort(sub.begin(),sub.end());
    return sub;
}*/
string GetSig(const string& a,int st,int ed)
{
    vector<int> vec;
    vec[a[ed-1]-'A']++;
    string res="";
    F(i,0,25) res+=to_string(vec[i])+",";
    return res;
}
int main()
{
//    ios::sync_with_stdio(false);
    int tt=read();
    F(Case,1,tt){
        cout<<"Case #"<<Case<<": ";
        string a,b;
        cin>>len>>a>>b;
        //cout<<"len="<<len<<endl;
        s.clear();
        F(i,0,len-1){
            F(j,i+1,len) s.insert(GetSig(b,i,j));
        }
        cout<<"~~~"<<s.size()<<endl;
        ans=0;
        F(i,0,len-1){
            F(j,1,len){
                string sig=GetSig(a,i,j);
                if(s.find(sig)!=s.end()) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
6
3
ABB
BAB
3
BAB
ABB
6
CATYYY
XXXTAC
9
SUBXXXXXX
SUBBUSUSB
4
AAAA
AAAA
19
PLEASEHELPIMTRAPPED
INAKICKSTARTFACTORY

 */