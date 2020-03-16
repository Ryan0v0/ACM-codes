//
// Created by 赵婉如 on 2019-08-22.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

const int maxn = 100000+10;
const int dem = 5;  //维数
const double INF = (1e200);

struct Point{
    double x[dem];
}p[maxn];

int n;
double minx[1<<dem], maxx[1<<dem];

double solve() {
    int tmp = 1<<dem;

    for(int i=0; i<tmp; i++) {
        minx[i] = INF;
        maxx[i] = -INF;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<tmp; j++) {
            int t = j;
            double s = 0;
            for(int k=0; k<dem; k++) {
                if(t & 1) s += p[i].x[k];
                else s -= p[i].x[k];
                t >>= 1;
            }
            if(maxx[j] < s) maxx[j] = s;
            if(minx[j] > s) minx[j] = s;
        }
    }

    double ans = -INF;
    for(int i=0; i<tmp; i++) {
        if(maxx[i] - minx[i] > ans)
            ans = maxx[i] - minx[i];
    }

    return ans;
}

int main(){

    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<dem; j++) {
                scanf("%lf", &p[i].x[j]);
            }
        }
        printf("%.2f\n", solve());
    }

    return 0;
}