//
// Created by 赵婉如 on 2019-08-22.
//
#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
#define INF 1000000000
using namespace std;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
const int N=1000010;
struct SAM{
    const static int maxn=2e5+7;
    int next[maxn][26],fail[maxn],len[maxn],cnt,last;
    LL f[maxn];LL ans;
    void init(){
        cnt=0; fail[0]=-1; len[0]=0; last=0;
        mec(next[0],0);
    }
    void add(int c) {
        int p=last,np=++cnt;f[cnt]=1LL;
        mec(next[np],0);
        len[np]=len[p]+1;
        for (;p!=-1&&!next[p][c]; p=fail[p]) next[p][c]=np;
        if (p==-1) fail[np]=0;
        else {
            int q=next[p][c];
            if (len[p]+1==len[q]) fail[np]=q;
            else {
                int nq=++cnt; len[nq]=len[p]+1;
                memcpy(next[nq],next[q],sizeof(next[q]));
                fail[nq]=fail[q];
                fail[np]=fail[q]=nq;
                for (;p!=-1&&next[p][c]==q; p=fail[p]) next[p][c]=nq;
            }
        } last=np;
    }
    void insert(char str[]) {
        int len=strlen(str),i;
        F(i,0,len-1) add(str[i]-'a');
    }

    char a[maxn];
    void dfs(int x=0,int dep=0){
        int i;
        printf("%-3d(fail:%-3d,len=%-2d):%s\n",x,fail[x],this->len[x],a);
        F(i,0,25){
            if (next[x][i]){
                a[dep]=i+'a';
                dfs(next[x][i],dep+1);
                f[x]+=f[next[x][i]];
                a[dep]=0;
            }
        }
        printf("**f[%d]=%d,len[%d]=%d\n",x,f[x],x,len[x]);
        if(f[x]!=1) ans=max(ans,f[x]*len[x]);
    }
}sam;
char s[N];
int main()
{
    scanf("%s",s);
    sam.init();
    sam.insert(s);
    sam.dfs(0);
    cout<<sam.ans<<endl;
    return 0;
}