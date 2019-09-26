//
// Created by 赵婉如 on 2019-08-17.
//


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int N = 1e4 + 10;
int n, k, sz, a[N];
char s[N];
bool cmp(int a,int b) {return a>b;}
int sum(int k){
    int ans = 0;
    for(int i=0;i<k && i<sz;i++) ans += a[i];
    return ans;
}
int main()
{
    while(scanf("%d%d", &n, &k)!=EOF){
        scanf("%s", s);
        int st = 0, ed = n-1;
        int top = 0, last = 0;
        while(st < n && s[st] == '1') st ++; top = st;
        if(k==0){
            printf("%d\n", top);
            continue;
        }
        while(st<=ed && s[ed] == '1') ed --; last = n-1-ed;
        int cnt = 0; sz = 0;
        for(int i=st;i<=ed;i++){
            if(s[i] == '0') {
                if(cnt) a[++sz] = cnt;
                cnt = 0;
            } else cnt ++;
        }
        sort(a+1, a+1+sz);
        int ans = 0;
        while(k > 2 && sz >= 1) ans += a[sz--], k -= 2;
        if(k==1) ans += max(top + last, a[sz]);
        else ans += max(top + a[sz], max(top + last, last + a[sz]));
        printf("%d\n", ans);
    }
    return 0;
}