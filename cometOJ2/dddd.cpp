#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i, x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef long long LL;
const int N=4005;
const int INT_INF = 0x3f3f3f3f;
const int INT_M_INF = 0x7f7f7f7f;
const LL LL_INF = 0x3f3f3f3f3f3f3f3f;
const LL LL_M_INF = 0x7f7f7f7f7f7f7f7f;
const int dr[] = {0, 0, -1, 1, -1, -1, 1, 1};
const int dc[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int MOD = 1e9 + 7;
const double pi = acos(-1.0);
const int MAXN = 4000 + 10;
const int MAXT = 3025 + 10;
using namespace std;
char s1[MAXN], s2[MAXN];
struct Node{
    int sum[27];
    bool operator < (const Node &rhs)const{
        for(int i = 0; i < 26; ++i){
            if(sum[i] != rhs.sum[i]) return sum[i] < rhs.sum[i];
        }
        return false;
    }
    Node operator - (const Node &rhs)const{
        Node tmp;
        for(int i = 0; i < 26; ++i){
            tmp.sum[i] = sum[i] - rhs.sum[i];
        }
        return tmp;
    }
}num1[MAXN], num2[MAXN];
set<Node> st;
int main(){
    scanf("%s%s", s1 + 1, s2 + 1);
    int len1 = strlen(s1 + 1);
    int len2 = strlen(s2 + 1);
    for(int i = 1; i <= len1; ++i){
        num1[i] = num1[i - 1];
        ++num1[i].sum[s1[i] - 'a'];
    }
    for(int i = 1; i <= len2; ++i){
        num2[i] = num2[i - 1];
        ++num2[i].sum[s2[i] - 'a'];
    }
    int len = min(len1, len2);
    bool ok = false;
    for(int i = len; i >= 1; --i){
        st.clear();
        for(int j = 1; j + i - 1 <= len1; ++j){
            st.insert(num1[j + i - 1] - num1[j - 1]);
        }
        for(int j = 1; j + i - 1 <= len2; ++j){
            if(st.count(num2[j + i - 1] - num2[j - 1])){
                ok = true;
                printf("%d\n", i);
                break;
            }
        }
        if(ok) break;
    }
    if(!ok) printf("0\n");
    return 0;
}