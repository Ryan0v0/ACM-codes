//
// Created by 赵婉如 on 2019-08-13.
// 10:01-10:30
// WA1 deque 会导致MLE,list操作与deque相同
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
int n,m;
//deque<int> que[150005];
list<int> que[150005];
int main()
{
    while(~scanf("%d%d",&n,&m)){
        //cout<<"size="<<sizeof(que[1])<<endl;
        F(i,1,n) que[i].clear();
        while(m--){
            int opt=read();
            int u=read(),w;
            int val,v;
            switch(opt){
                case 1:
                    w=read();
                    val=read();
                    if(w==0) que[u].push_front(val);
                    else if(w==1) que[u].push_back(val);
                    break;
                case 2:
                    w=read();
                    if(que[u].empty()){
                        puts("-1");
                    }
                    else if(w==0){
                        cout<<que[u].front()<<endl;
                        que[u].pop_front();
                    }else if(w==1){
                        cout<<que[u].back()<<endl;
                        que[u].pop_back();
                    }
                    break;
                case 3:
                    v=read();
                    w=read();
                    if(w==0){
                        que[u].insert(que[u].end(),que[v].begin(),que[v].end());
                        que[v].clear();
                    }else if(w==1){
                        que[u].insert(que[u].end(),que[v].rbegin(),que[v].rend());
                        que[v].clear();
                    }
                    break;
            }
        }
    }
    return 0;
}
/*
2 10
1 1 1 23
1 1 0 233
2 1 1
1 2 1 2333
1 2 1 23333
3 1 2 1
2 2 0
2 1 1
2 1 0
2 1 1

 */