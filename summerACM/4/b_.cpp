//
// Created by 赵婉如 on 2019-08-14.
//

#include <bits/stdc++.h>
#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i,x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef unsigned long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
inline LL myPow(LL a,LL b,LL mod){
    LL  res=1LL;
    for (; b; b>>=1LL,a=a*a%mod)
        if (b&1) res=res*a%mod;
    return res;
}
int startTime;
void startTimer() {startTime=clock();}
void printTimer() {debug("/--- Time: %ld milliseconds ---/\n",clock()-startTime);}
const int N=1e5+10,M=2e5+10;

struct SAM{
    const static int maxn=2e5+7;
    int next[maxn][26],fail[maxn],len[maxn],cnt,last;
    void init(){
        cnt=0; fail[0]=-1; len[0]=0; last=0;
        mec(next[0],0);
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
    void dfs(int x=0,int len=0){
        int i;
        printf("%-3d(fail:%-3d,len=%-2d):%s\n",x,fail[x],this->len[x],a);   `````1
        F(i,0,25){
            if (next[x][i]){
                a[len]=i+'a';
                dfs(next[x][i],len+1);
                a[len]=0;
            }
        }
    }
}sam;
int lz[N<<2];
LL sum[N<<2];
void push_up(int p)
{
//    sum[p]=sum[p<<1]+sum[p<<1|1]+(LL)lz[p]*(R-L+1);
}
void add(int p,int l,int r,int L,int R)//区间加
{
    if(l<=L&&R<=r){
        lz[p]++;sum[p]+=(R-L+1);
        return;
    }
    int mid=(L+R)>>1;
    if(l<=mid) add(p<<1,l,r,L,mid);
    if(r> mid) add(p<<1|1,l,r,mid+1,R);
    //push_up(p);
    sum[p]=sum[p<<1]+sum[p<<1|1]+(LL)lz[p]*(R-L+1);
}
LL get_sum(int p,int l,int r,int L,int R)
{
    if(L>R) return 0;
    if(l<=L&&R<=r) return sum[p];
    int mid=(L+R)>>1;
    LL res=(LL)lz[p]*(min(r,R)-max(l,L)+1);
    if(l<=mid) res+=get_sum(p<<1,l,r,L,mid);
    if(r> mid) res+=get_sum(p<<1|1,l,r,mid+1,R);
    return res;
}
char que[N],str[N];
int L[N];
LL ans[N];
vector<pair<int,int>> q[N];
int n,m;
//#define DEBUG
int main()
{
    //#ifdef DEBUG
    freopen("curse.in","r",stdin);
    //#endif
    int tt=read();
    F(Case, 1, tt) {
        scanf("%s%s",que+1,str);
        m=read();
        sam.init();
        sam.insert(str);
        sam.solve(que,L);
        n=strlen(que+1);
        //cout<<m<<' '<<n<<endl;
        F(i,1,n) q[i].clear();
        F(i,1,m){
            int l=read();int r=read();
            q[r].push_back(make_pair(l,i));
        }
        F(i,1,n*4) sum[i]=lz[i]=0;
        F(i,1,n){
            if(L[i]) add(1,i-L[i]+1,i,1,n);
            for(auto j:q[i]){
                ans[j.second]=get_sum(1,j.first,i,1,n);
            }
        }
        cout << "Case " << Case << ": " <<endl;
        F(i,1,m) cout<< ans[i] << endl;
    }
    //printTimer();
    //printf("Time cost : %lf s\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
/*
1
yqahbyyoxltryqdmvenema
nbakglgqolxnaifnqtoclnnqiabpzoelisnuniugudjnqnpxmvdpy
50
15 17
10 19
14 16
3 5
20 22
5 21
15 16
12 14
15 22
22 22
1 1
12 16
16 20
19 22
4 7
16 21
9 17
12 18
16 19
20 22
18 22
6 20
19 22
17 17
5 12
8 21
2 9
4 12
6 13
12 15
19 19
21 21
11 14
12 21
14 20
6 15
12 20
17 22
2 10
2 18
9 20
18 22
17 20
16 18
13 19
15 18
14 14
9 11
18 19
6 10

1
r
wiuotcg
50
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1


 */