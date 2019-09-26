//
// Created by 赵婉如 on 2019-07-26.
//

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int q, m;
#define pa pair<string,string>
list<pa> lt;
unordered_map<string, list<pa>::iterator> mp;
typedef long long LL;
inline LL read()
{
    LL x=0LL,f=1LL;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1LL;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10LL*x+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    int tt = read();
    while (tt--) {
        int q = read();
        int m = read();
        lt.clear();
        mp.clear();
        while (q--) {
            int op;
            char s[20];
            scanf("%d%s", &op, s);
            if (op == 0) {
                char v[20];
                scanf("%s", v);
                if (mp.find(s) != mp.end()) {
                    auto it = mp[s];
                    strcpy(v, (*it).second.data());
                    lt.erase(it);
                }
                lt.emplace_back(make_pair(s,v));
                mp[s] = prev(lt.end());
                //cout<<v<<endl;
                printf("%s\n", v);
                if ((int) lt.size() > m) {
                    mp.erase((*lt.begin()).first);
                    lt.pop_front();
                }
            } else {
                int v;
                scanf("%d", &v);
                if (mp.find(s) == mp.end()) {
                    //puts("Invalid");
                    printf("Invalid\n");
                    continue;
                }
                auto pos = mp[s];
                if ((pos == lt.begin() && v == -1) ||
                    (next(pos) == lt.end() && v == 1)) {
                    //puts("Invalid");
                    printf("Invalid\n");
                    continue;
                }
                if (v == 1) pos = next(pos);
                else if (v == -1) pos = prev(pos);
                //cout<<((*pos).second.data())<<endl;
                printf("%s\n", (*pos).second.data());
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