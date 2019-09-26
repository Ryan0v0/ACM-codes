//
// Created by 赵婉如 on 2019-08-29.
//

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
    cout<<current<<' '<<f[current]<<endl;
    string result = "";
    for(int i = 0; i < 26; i++) {
        result += to_string(f[i]) + ",";
    }
    return result;
}

int main() {
    F(i,1,4000) cout<<'a';cout<<endl;
    F(i,1,4000) cout<<'a';cout<<endl;
}

/*
grandmother
anagram
0 1
0 2
0 3
0 4
1 6
5 11
6

0 1
0 2
1 4
1 5
1 6
5

 */