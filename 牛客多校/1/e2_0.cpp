//
// Created by 赵婉如 on 2019-08-24.
//

/*
ID: hepic
PROG: sabotage
LANG: C++11
*/
#include <bits/stdc++.h>

#define FOR(i, a, b) for(auto i=a; i<=b; ++i)
#define REP(i, a, b) for(auto i=a; i<b; ++i)
#define FORI(i, a, b) for(auto i=a; i!=b+1-2*(a>b); i+=1-2*(a>b))
#define REPI(i, a, b) for(auto i=a-(a>b); i!=b-(a>b); i+=1-2*(a>b))
#define ALL(v) v.begin(),v.end()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define eb(a, b) emplace_back(a, b)
#define fir first
#define sec second
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define type(x) typeid(x).name()
#define ms(arr, val) memset(arr, val, sizeof(arr))
#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)
#define PI acos(-1)
#define open_read1 freopen("a.txt", "r", stdin)
#define open_write1 freopen("b.xt", "w", stdout)
#define open_read freopen("sort.in", "r", stdin)
#define open_write freopen("sort.out", "w", stdout)

using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<double, double> PDD;
typedef pair<int, int> PII;
typedef pair<int, PII> PIPII;
typedef pair<PII, PII> PPIIPII;
typedef pair<LL, LL> PLL;
typedef pair<ULL, ULL> PUU;
typedef pair<LL, PLL> PLPLL;
typedef pair<PLL, PLL> PPLLPLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;


template<typename T, typename T1>
ostream& operator << (ostream &out, pair<T, T1> obj)
{
    out << "(" << obj.first << ", " << obj.second << ")";
    return out;
}


template<typename T, typename T1>
ostream& operator << (ostream &out, map<T, T1> cont)
{
    typename map<T, T1>::const_iterator itr = cont.begin();
    typename map<T, T1>::const_iterator ends = cont.end();

    for(; itr!=ends; ++itr)
        out<<*itr<<" ";
    out<<endl;

    return out;
}


template<typename T>
ostream& operator << (ostream &out, set<T> cont)
{
    typename set<T>::const_iterator itr = cont.begin();
    typename set<T>::const_iterator ends = cont.end();

    for(; itr!=ends; ++itr)
        out<<*itr<<" ";
    out<<endl;

    return out;
}


template<typename T>
ostream& operator << (ostream &out, multiset<T> cont)
{
    typename multiset<T>::const_iterator itr = cont.begin();
    typename multiset<T>::const_iterator ends = cont.end();

    for(; itr!=ends; ++itr)
        out<<*itr<<" ";
    out<<endl;

    return out;
}


template<typename T, template<typename ELEM, typename ALLOC=allocator<ELEM>> class CONT>
ostream& operator << (ostream &out, CONT<T> cont)
{
    typename CONT<T>::const_iterator itr = cont.begin();
    typename CONT<T>::const_iterator ends = cont.end();

    for(; itr!=ends; ++itr)
        out<<*itr<<" ";
    out<<endl;

    return out;
}


template<typename T, unsigned int N, typename CTy, typename CTr>
typename enable_if<!is_same<T, char>::value, basic_ostream<CTy, CTr> &>::type
operator << (basic_ostream<CTy, CTr> &out, const T (&arr)[N])
{
    REP(i, 0, N)
        out<<arr[i]<<" ";
    out<<endl;

    return out;
}


template<typename T>
T gcd(T a, T b)
{
    T min_v = min(a, b);
    T max_v = max(a, b);

    while(min_v)
    {
        T temp = max_v % min_v;
        max_v = min_v;
        min_v = temp;
    }

    return max_v;
}


template<typename T>
T lcm(T a, T b)
{
    return (a*b) / gcd(a, b);
}


template<typename T>
T fast_exp_pow(T base, T exp, T mod)
{
    T res = 1;

    while(exp)
    {
        if(exp&1)
        {
            res *= base;
            res %= mod;
        }

        exp >>= 1;
        base *= base;
        base %= mod;
    }

    return res % mod;
}

/*#################################################################################################################
#################################################################################################################
################################################################################################################
#################################################################################################################*/

#define SIZE 110

int T, N, M, P;
int one[SIZE], zero[SIZE];
int dpWays[SIZE * SIZE][2];
string pref[SIZE], forb[SIZE];


void calculate() {
    REP (i, 0, P) {
        if (!i) {
            ++dpWays[zero[i]][0];
            ++dpWays[one[i]][0];
            continue;
        }

        for (int j = SIZE * SIZE - 1; j >= 0; --j) {
            if (j - zero[i] >= 0) {
                dpWays[j][1] += dpWays[j - zero[i]][0];
            }

            if (j - one[i] >= 0) {
                dpWays[j][1] += dpWays[j - one[i]][0];
            }
        }

        REP (j, 0, SIZE * SIZE) {
            dpWays[j][0] = dpWays[j][1];
            dpWays[j][1] = 0;
        }
    }
}


int main() {
    scanf("%d", &T);

    FOR (t, 1, T) {
        scanf("%d%d%d", &N, &M, &P);

        REP (i, 0, N) {
            cin >> pref[i];
        }

        REP (i, 0, M) {
            cin >> forb[i];
        }

        ms(zero, 0);
        ms(one, 0);

        REP (i, 0, P) {
            REP (j, 0, N) {
                if (pref[j][i] == '0') {
                    ++zero[i];
                } else {
                    ++one[i];
                }
            }
        }

        ms(dpWays, 0);
        calculate();

        REP (i, 0, M) {
            int cnt = 0;

            REP (j, 0, P) {
                if (forb[i][j] == '0') {
                    cnt += one[j];
                } else {
                    cnt += zero[j];
                }
            }

            --dpWays[cnt][0];
        }

        FOR (i, 0, N * P) {
            if (dpWays[i][0] > 0) {
                printf("Case #%d: %d\n", t, i);
                break;
            }
        }
    }

    return 0;
}
