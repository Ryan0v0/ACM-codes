//
// Created by 赵婉如 on 2019-08-22.
//
#include <bits/stdc++.h>
#define F(i,s,t) for(int i=(s);i<=(t);i++)
#define D(i,s,t) for(int i=(s);i>=(t);i--)
#define mec(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
typedef long long ll;
const LL maxn=2e5+107;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
vector<int> edge[maxn];
namespace ACM {
    const int maxn=2e5+7;
    int nxt[maxn][26],fail[maxn],len[maxn],tot;
    ll cnt[maxn];
    void init() {
        tot=0; len[0]=0; fail[0]=0; cnt[0]=0;
        memset(nxt[0],0,sizeof(nxt[0]));
    }
    int insert(char s[]) {
        int i,n=strlen(s),p=0;
        REP(i,n) {
            int c=s[i]-'a';
            if (!nxt[p][c]) {
                nxt[p][c]=++tot; len[tot]=len[p]+1; fail[tot]=0;
                memset(nxt[tot],0,sizeof(nxt[tot])); cnt[tot]=0;
            } p=nxt[p][c];
        } cnt[p]++;
        return p;
    }
    void buildAC() {
        static int Q[maxn],ST,ED;
        ST=0; ED=-1; Q[++ED]=0;
        while (ST<=ED) {
            int p=Q[ST++],c;
            cnt[p]+=cnt[fail[p]];
            REP(c,26) {
                if (nxt[p][c]) {
                    fail[nxt[p][c]]=p?nxt[fail[p]][c]:0;
                    Q[++ED]=nxt[p][c];
                } else nxt[p][c]=p?nxt[fail[p]][c]:0;
            }
        }
    }
    void dfs(int p=0,int l=0) {
        static char s[maxn];
        printf("%-20s  p=%d(fail=%d;len=%d) cnt=%lld\n",s,p,fail[p],len[p],cnt[p]);
        int c;
        REP(c,26) if (nxt[p][c]){
            if (nxt[p][c]&&len[p]+1==len[nxt[p][c]]) {
                s[l]=c+'a'; dfs(nxt[p][c],l+1); s[l]=0;
            }
        }
    }
}
ll C[maxn],D[maxn];
int id[maxn];
char so[maxn];
char pool[maxn*3],*st=pool;
char *str[maxn];
ll ANS1,ANS2;
void ADDANS(ll x) {
    ANS2+=x; ANS1+=ANS2/10000000000ll;
    ANS2%=10000000000ll;
}
void PRINTANS(){
    if (ANS1) printf("%lld%010lld",ANS1,ANS2);
    else printf("%lld",ANS2);
}
int main() {
    int n,i;
    scanf("%s",so);
    int len=strlen(so);
    scanf("%d",&n);
    ACM::init();
    REP(i,n) {
        str[i]=st;
        scanf("%s",str[i]);
        int l=strlen(str[i]);
        ACM::insert(str[i]);
        reverse(str[i],str[i]+l);
        st+=l+2;
    } ACM::buildAC();
    puts("--------------dfs1--------------");
     ACM::dfs();//
    int p=0;
    REP(i,len) {
        int c=so[i]-'a';
        p=ACM::nxt[p][c];
        C[i]=ACM::cnt[p];
    }

    ACM::init();
    REP(i,n) {
        int l=strlen(str[i]);
        ACM::insert(str[i]);
        reverse(str[i],str[i]+l);
    } ACM::buildAC();
    puts("--------------dfs2--------------");
     ACM::dfs();//
    p=0;
    rREP(i,len) {
        int c=so[i]-'a';
        p=ACM::nxt[p][c];
        D[i]=ACM::cnt[p];
    }
    puts("--------------debug--------------");
     REP(i,len) printf("%d %d\n",C[i],D[i]);
    REP(i,len-1) ADDANS((ll)C[i]*D[i+1]);
    PRINTANS();
}
/*
abcdefg
4
cd
ef
bcd
efg

 */