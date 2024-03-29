//
// Created by 赵婉如 on 2019-07-24.
//

#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int n, m, k;
int a[N];
long long bst[N];
long long psum[N];

long long sum(int l, int r){
    l = max(l, 0);
    return psum[r] - (l == 0? 0 : psum[l - 1]);
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        psum[i] = a[i] + (i == 0? 0 : psum[i - 1]);
    }

    long long res = 0;
    for(int len = 1; len <= m && len <= n; ++len)
        res = max(res, sum(0, len - 1) - k);
    for(int i = 0; i < n; ++i){
        if(i + 1 >= m){
            long long nbst = sum(i - m + 1, i) - k;
            if(i - m >= 0) nbst += bst[i - m];
            bst[i] = max(bst[i], + nbst);
        }

        for(int len = 0; len < m && i + len < n; ++len)
            res = max(res, bst[i] + sum(i + 1, i + len) - k * (len > 0));
    }/*
    for(int i=0;i<n;i++){
        cout<<psum[i]<<' ';
    }
    cout<<endl;
*/
    cout << res << endl;
    return 0;
}
//2 -2 13 10 14 22 25