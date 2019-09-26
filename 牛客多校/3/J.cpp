//
// Created by 赵婉如 on 2019-07-25.
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
const int N=20;
string str;
map<string,int> mp;
map<string,int> id;
map<int,string> val;
//map<char*,int>::iterator iit;
//deque<pair<char*,int> >q;
//deque<char*> q;
//vector<char*> q;
set<string> s;
set<string>::iterator it;
int main()
{
    //it=q.begin();
    //if(q.count(s)) q.erase(*it);
    int tt=read();
    while(tt--){
        int q=read();int n=read();
        while(q--){
            int opt=read();cin>>str;int k=read();
            //scanf("%d%s%d",&opt,str,&k);
            cout<<opt<<' '<<str<<' '<<k<<endl;
            if(opt==0){
                if(s.count(str)){
                    //cout<<"~~1~~"<<endl;
                    cout<<mp[str]<<endl;
                }else{
                    //cout<<"~~2~~"<<endl;
                    s.insert(str);
                    it=s.begin();
                    mp[str]=k;
                    if(s.size()>n){
                        //cout<<"jiayou"<<endl;
                        //cout<<"!"<<*it<<endl;
                        s.erase(*it);
                        it=s.begin();
                        //cout<<"~!"<<*it<<endl;
                    }
                    id[str]=s.size();
                    val[id[str]]=str;
                    cout<<k<<endl;
                }//q.pop_front
                //if(mp.find()) mp[s]=k;
                //else
                //id.find()
            }else if(opt==1){
                if(s.count(str)){
                    //iit=id.find(id[str]+k);
                    cout<<mp[val[id[str]+k]]<<endl;
                }else{
                    puts("Invalid");
                }
            }
        }
    }
    return 0;
}
/*
1
8 3
0 0101010 1
0 0101011 2
1 0101010 1
0 1100000 3
0 0101011 -1
0 1111111 4
1 0101011 -1
1 0101010 0

*/