#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i, x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;

inline LL read() {
    LL x = 0LL, f = 1LL;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1LL;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10LL * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}

unordered_set<string> s;/*
string GetSig(const string& a,int st,int ed)
{
    string sub=a.substr(st,ed-st);
    sort(sub.begin(),sub.end());
    return sub;
}*/
string GetSig(const string &a, int st, int ed) {
    vector<int> vec;
    vec[a[ed - 1] - 'a']++;
    string res = "";
    F(i, 0, 25) res += to_string(vec[i]) + ",";
    //cout<<"!!!"<<res<<endl;
    return res;
}

string a, b;
int n, m;
LL ans;

int main() {
//    ios::sync_with_stdio(false);
    cin >> a >> b;
    n = a.length();
    m = b.length();
    s.clear();
    F(i, 0, m - 1) {
        F(j, i + 1, m) s.insert(GetSig(b, i, j)),cout<<i<<' '<<j<<endl;;
    }
    ans = 0;
    F(i, 0, n - 1) {
        F(j, i+1, n) {
            string sig = GetSig(a, i, j);
            if (s.find(sig) != s.end()) ans = max(ans, (LL)(j - i));
        }
    }
    cout << ans << endl;
    return 0;
}
/*
anagram
grandmother

 */