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
int a[1010];
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i < n; i++) {
        bool ok1 = false, ok2 = false;
        for (int j = 1; j < i; j++) if (a[j] < a[i]) ok1 = true;
        for (int j = i + 1; j <= n; j++) if(a[i] < a[j]) ok2 = true;
        if (ok1 && ok2) cnt++;
    }
    cout << cnt << endl;
    return 0;
}