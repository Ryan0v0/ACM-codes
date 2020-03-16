//
// Created by 赵婉如 on 2020-03-16.
//


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int solve(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        int last = 10;
        bool flag = true;
        while (tmp) {
            int x = tmp % 10;
            if(x > last) {
                flag = false;
                break;
            }
            last = x;
            tmp /= 10;
        }
        if (flag) cnt++;
    }
    return cnt;
}
int main() {
    int n;
    scanf("%d", &n);
    cout << solve(n) << endl;
    return 0;
}