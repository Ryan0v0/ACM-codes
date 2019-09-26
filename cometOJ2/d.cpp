//
// Created by 赵婉如 on 2019-08-29.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define R(i, x) for(int i=head[(x)];i;i=e[i].next)
#define mec(a, x) memset(a,x,sizeof(a))
using namespace std;
typedef unsigned long long LL;

// string GetSig(const string& a, int start, int end) {
//     string sub = a.substr(start, end - start);
//     sort(sub.begin(), sub.end());
//     return sub;
// }

string GetSig(const string& a, int start, int end, vector<int>& f) {
    int current = a[end - 1] - 'a';
    f[current]++;
    string result = "";
    for(int i = 0; i < 26; i++) {
        result += to_string(f[i]) + ",";
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
        string a, b;
        cin >> a >> b;
        int n=a.length();int m=b.length();
        unordered_set<string> all_b;
        for(int i = 0; i < m; i++) {
            vector<int> f(26);
            for(int j = i + 1; j <= m; j++) {
                all_b.insert(GetSig(b, i, j, f));
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++) {
            vector<int> f(26);
            for(int j = i + 1; j <= n; j++) {
                string sig = GetSig(a, i, j, f);
                if (all_b.find(sig) != all_b.end()) {
                    //cout<<i<<' '<<j<<endl;
                    //cout<<"!!!"<<*(all_b.find(sig))<<endl;
                    result=max(result,j-i);
                }
            }
        }
        cout<<result<<endl;
    return 0;
}

/*
grandmother
anagram

 */