//
// Created by 赵婉如 on 2019-08-22.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <ctime>
#include <iomanip>
using namespace std;
typedef long long LL;
typedef double DB;
#define MIT (2147483647)
#define INF (1000000001)
#define MLL (1000000000000000001LL)
#define sz(x) ((int) (x).size())
#define clr(x, y) memset(x, y, sizeof(x))
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define ft first
#define sd second
#define mk make_pair

inline int Getint()
{
    int Ret = 0;
    char Ch = ' ';
    bool Flag = 0;
    while(!(Ch >= '0' && Ch <= '9'))
    {
        if(Ch == '-') Flag ^= 1;
        Ch = getchar();
    }
    while(Ch >= '0' && Ch <= '9')
    {
        Ret = Ret * 10 + Ch - '0';
        Ch = getchar();
    }
    return Flag ? -Ret : Ret;
}

const int N = 200010;
const DB SQRT2 = sqrt(2.0);
class Point
{
//    private : static const double AAAAA = sqrt(234);
public :
    int x, y, index;
    inline void Read()
    {
        x = Getint();
        y = Getint();
    }

    inline bool operator <(const Point &a) const
    {
        if(x != a.x) return x < a.x;
        return y < a.y;
    }

    static DB Dist(const Point &a, const Point &b)
    {
        int dx = abs(a.x - b.x), dy = abs(a.y - b.y);
        if(dx < dy) swap(dx, dy);
        return SQRT2 * dy + (dx - dy);
    }

    inline const DB Feature()
    {
        return SQRT2 * y + (x - y);
    }
} data[N];
int n;
int st, far;
DB ans;
class Hash
{
private :
    int arr[N], length;

public :
    inline void Clear()
    {
        length = 0;
    }

    inline void Insert(int x)
    {
        arr[++length] = x;
    }

    inline void GoHash()
    {
        sort(arr + 1, arr + 1 + length);
        length = unique(arr + 1, arr + 1 + length) - (arr + 1);
        //for(int i = 1; i <= length; i++) printf("%d\n", arr[i]);
    }

    inline int GetIndex(int x)
    {
        int left = 1, right = length, mid;
        while(left <= right)
        {
            mid = (left + right) >> 1;
            if(arr[mid] < x) left = mid + 1;
            else if(arr[mid] > x) right = mid - 1;
            else return mid;
        }
        return 0;
    }

    inline int GetLength()
    {
        return length;
    }
} ranks;

class TreeArray
{
private :
    DB value[N];
    int index[N], n;

public :
    inline void Clear()
    {
        n = 0;
    }

    inline void SetLimit(int x)
    {
        n = x;
        for(int i = 1; i <= n; i++) value[i] = -1.0 * INF;
    }

    inline int Lowbit(int x)
    {
        return x & (-x);
    }

    inline void Add(Point a)
    {
        int x = ranks.GetIndex(a.y - a.x);
        //printf("%d %d %d\n", a.y - a.x, x, n);
        DB val = a.Feature();
        for( ; x <= n; x += Lowbit(x))
            if(val > value[x])
                value[x] = val, index[x] = a.index;
    }

    inline void Query(const Point &a, DB &cnt, int &idx)
    {
        cnt = -1.0 * INF, idx = 0;
        int x = ranks.GetIndex(a.y - a.x);
        for( ; x; x -= Lowbit(x))
            if(cnt < value[x])
                cnt = value[x], idx = index[x];
    }
} Store;

inline void Input()
{
    n = Getint();
    for(int i = 1; i <= n; i++)
    {
        data[i].Read();
        data[i].index = i;
    }
}

inline void Solve()
{
    //puts("adf");
    ans = -1.0 * INF, st = far = 1;
    for(int dir = 0; dir < 4; dir++)
    {
        //puts("asdfff");
        if(dir == 1 || dir == 3)
        {
            for(int i = 1; i <= n; i++)
                swap(data[i].x, data[i].y);
        }
        else if(dir == 2)
        {
            for(int i = 1; i <= n; i++)
                data[i].x = -data[i].x;
        }


        ranks.Clear();
        for(int i = 1; i <= n; i++)
            ranks.Insert(data[i].y - data[i].x);
        ranks.GoHash();

        sort(data + 1, data + 1 + n);
        for(int i = 1; i <= n; i++)
            Store.Clear();
        Store.SetLimit(ranks.GetLength());
        //puts("asdfffffx");
        for(int i = n; i >= 1; i--)
        {
            //printf("%d", i);
            DB cnt;
            int idx;
            Store.Query(data[i], cnt, idx);
            //puts("xxx");
            if(idx)
            {
                cnt -= data[i].Feature();
                if(cnt > ans) ans = cnt, st = data[i].index, far = idx;
            }
            Store.Add(data[i]);
            //puts("yyy");
        }
    }

    printf("%d %d\n", st, far);
}

int main()
{
    Input();
    Solve();
    return 0;
}