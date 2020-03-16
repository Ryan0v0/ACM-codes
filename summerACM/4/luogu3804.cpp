//
// Created by 赵婉如 on 2019-08-14.
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
LL ans;
struct SAM{
    const static int maxn=3e6+7;
    int next[maxn][26],fail[maxn],len[maxn],cnt,last;
    void init(){
        cnt=0; fail[0]=-1; len[0]=0; last=0;
        mec(next[0],0);
    }
    int tot=0,head[maxn];
    struct edge{int fro,go,next;}e[maxn<<1];
    void addedge(int x,int y){
        e[++tot]=(edge){x,y,head[x]};head[x]=tot;
        //e[++tot]=(edge){y,x,head[y]};head[y]=tot;
    }
    void debug(){
        puts("-----debug-----");
        F(i,1,tot){
            cout<<e[i].fro<<' '<<e[i].go<<' '<<endl;
        }
        puts("-----debug-----");
    }
    void add(int c) {
        int p=last,np=++cnt;
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
    void buildtree(){
	    F(i,0,cnt) addedge(fail[i],i);
	    debug();
	    //cout<<cnt<<" "<<tot<<endl;
    }
    void solve(char str[],int L[]) {
        int l=0,p=0,length=strlen(str+1),i;
        F(i,1,length) {
            int c=str[i]-'a';
            while (p&&!next[p][c]) p=fail[p],l=len[p];
            if (next[p][c]) {
                p=next[p][c]; l++;
            } L[i]=l;
        }
    }

    char a[maxn];
    void dfs_(int x=0,int len=0){
        int i;
        printf("%-3d(fail:%-3d,len=%-2d):%s\n",x,fail[x],this->len[x],a);
        F(i,0,25){
            if (next[x][i]){
                a[len]=i+'a';
                dfs_(next[x][i],len+1);
                a[len]=0;
            }
        }
    }
    int siz[maxn];
    void dfs(int x) {
        R(i, x) {
            int y = e[i].go;
            dfs(y);
            siz[x] += siz[y];
        }
        cout<<x<<' '<<siz[x]<<endl;
        if (siz[x] != 1) ans = max(ans, (LL) siz[x] * len[x]);
    }
}sam;
const int N=3e6+7; 
char s[N];
int main()
{
    scanf("%s",s);
    sam.insert(s);
    sam.dfs_();
    sam.buildtree();
    sam.dfs(1);
    cout<<ans<<endl;
    return 0;
}
