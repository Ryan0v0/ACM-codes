//
// Created by 赵婉如 on 2019-08-31.
//
#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
#define inf 10000000000000000////
using namespace std;
typedef long long LL;

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

vector<int> op;

void solve(int x, int y, int dx, int dy) {
    bool flag = 0;
    while (1) {
        //cout<<x<<' '<<y<<endl;
        if (x >= y) {
            puts("No");
            break;
        }
        if (flag) {
            puts("No");
            break;
        }
        if (x == dx && y == dy) {
            puts("Yes");
            while(!op.empty()){
                int x=op[op.size()-1];
                if (x == 1) cout << "B";
                if (x == 0) cout << "A";
                op.pop_back();
            }/*
            D(i, (LL) op.size() - 1, 0) {
                if (op[i] == 1) cout << "B";
                if (op[i] == 0) cout << "A";
            }*/
            cout << endl;
            break;
        }
        if((x+y)%2!=0){
            flag=1;
            continue;
        }
        int mid = (x + y) / 2.0;
        if (mid > dx && mid < dy) {
                flag = 1;
                continue;
        }//不else
        if (mid <= dx) {
            //cout<<"!!!"<<endl;
            x = mid, op.push_back(1);
        } else if (mid >= dy) {
            y = mid, op.push_back(0);
        }
    }
}

int main() {
    int tt = read();
    while (tt--) {
        LL a = read();
        LL b = read();
        LL c = read();
        LL d = read();
        //op.clear();
        if (a == b) {
            if (c == d) {
                puts("Yes");
                puts("");
                continue;
            } else {
                puts("No");
                continue;
            }
        }else if(c==d){
            puts("No");
            continue;
        } else {
            if ((a-b<0&&c-d>0)||(a-b>0&&c-d<0)){
                puts("No");
                continue;
            }
            if (a > b) {
                swap(a, b);
                swap(c, d);
            }
            if (d < a || b < c) {
                puts("No");
                continue;
            } else solve(c, d, a, b);
        }
    }
    return 0;
}

/*
4
0 1 2 3
0 1 0 1
0 1 -1 3
0 1 0 3

 */