#include <bits/stdc++.h>

#define F(i, s, t) for(int i=(s);i<=(t);i++)
#define D(i, s, t) for(int i=(s);i>=(t);i--)
#define mec(a, x) memset(a,x,sizeof(a))
#define eps 1e-15
//#define sgn(x) (((x)<)?(−1):(1))
//#define double long double
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

inline int sgn(long double x) {
    if (fabs(x) < eps) return 0;
    else if (x < 0) return -1;
    else return 1;
}
//typedef long double LD;
//const LD eps = 1e-10;
/*
int dcmp(LD x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}*/

//LD sqr(LD x) { return x * x; }

struct Point {
    long double x, y;

    Point(long double x = 0, long double y = 0) : x(x), y(y) {}

    //返回两点的距离
    long double distance(Point p) { return hypot(x - p.x, y - p.y); }

    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }

    Point operator*(const long double &k) const {

        return Point(x * k, y * k);
    }

    Point operator-(const Point &b) const {

        return Point(x - b.x, y - b.y);
    }

    Point operator/(const long double &k) const {

        return Point(x / k, y / k);
    }

    //逆时针旋转 90 度
    Point rotleft() { return Point(-y, x); } //顺时针旋转 90 度
    Point rotright() { return Point(y, -x); }

    //返回长度
    long double len() { return hypot(x, y); }

    //化为长度为 r 的向量
    Point trunc(long double r) {

        long double l = len();

        if (!sgn(l))return *this;

        r /= l;

        return Point(x * r, y * r);
    }
};

struct Circle {
    Point p;
    long double r;

    Circle(Point c, long double r) : p(c), r(r) {}

    Circle(long double x, long double y, long double r) : p(x, y), r(r) {}//
};

int w, h;
int length[5];

//Point p1(0, 0);
Point p(0.0, 0.0), p2, p3, p4;
long double r;


int relationcircle(Circle v) {
    long double d = p.distance(v.p);
    //cout<<"dis:"<<p.x<<' '<<p.y<<' '<<v.p.x<<' '<<v.p.y<<' '<<r<<' '<<v.r<<endl;
    if (sgn(d - r - v.r) > 0)return 5;
    if (sgn(d - r - v.r) == 0)return 4;
    long double l = fabs(r - v.r);
    if (sgn(d - r - v.r) < 0 && sgn(d - l) > 0)return 3;
    if (sgn(d - l) == 0)return 2;
    if (sgn(d - l) < 0)return 1;
}

int pointcrosscircle(Circle v, Point &p1, Point &p2) {

    int rel = relationcircle(v);
    //cout<<"rel="<<rel<<endl;
    if (rel == 1 || rel == 5) return 0;
    long double d = p.distance(v.p);
    long double l = (d * d + r * r - v.r * v.r) / (2 * d);
    long double h = sqrt(r * r - l * l);
    Point tmp = p + (v.p - p).trunc(l);
    p1 = tmp + ((v.p - p).rotleft().trunc(h));
    //cout<<"p1="<<p1.x<<' '<<p1.y<<endl;
    p2 = tmp + ((v.p - p).rotright().trunc(h));
    //cout<<"p2="<<p2.x<<' '<<p2.y<<endl;
    if (rel == 2 || rel == 4) return 1;
    return 2;

}
struct node{
    int l,id;
}a[5];
bool cmp(node x,node y){
    return x.l>y.l;
}
int main() {
    int tt = read();
    while (tt--) {
        scanf("%d%d%d%d%d", &w, &h, &a[1].l, &a[2].l, &a[3].l);
        a[1].id=1;a[2].id=2;a[3].id=3;
        //if (w < h) swap(w, h);//w>=h
        //int mx=max(w,h);
        sort(a + 1, a + 3 + 1,cmp);
        if (w >= h) {
            if (a[1].l <= w) {
                p2.x = (long double)a[1].l, p2.y = 0.0;
            } else {
                long double y = sqrt((long double) (a[1].l * a[1].l - w * w));
                p2.x = (long double)w, p2.y = (long double)y;
            }
        }
        else {
            if (a[1].l <= h) {
                p2.y = (long double)a[1].l, p2.x = 0.0;
            } else {
                long double x = sqrt((long double) (a[1].l * a[1].l - h * h));
                p2.y = (long double)h, p2.x = (long double)x;
            }
        }
        r=(long double)a[2].l;p.x=0.0;p.y=0.0;
        Circle v(p2, (long double)a[3].l);
        pointcrosscircle(v, p3, p4);
        //cout<<p2.x<<"@#R"<<endl;
        if (sgn(p3.x-0.0)>=0 && sgn(p3.x-(long double)w)<=0 && (p3.y-0.0)>=0 && (p3.y-(long double)h)<=0) {
            //cout<<"!!!"<<endl;
            //cout<<a[1].id<<' '<<a[2].id<<' '<<a[3].id<<endl;
            if(a[1].id==1&&a[2].id==2&&a[3].id==3) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p.x, p.y, p2.x, p2.y, p3.x, p3.y);
            }
            if(a[1].id==1&&a[2].id==3&&a[3].id==2) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p2.x, p2.y, p.x, p.y, p3.x, p3.y);
            }
            if(a[1].id==2&&a[2].id==1&&a[3].id==3) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p.x, p.y, p3.x, p3.y, p2.x, p2.y);
            }
            if(a[1].id==2&&a[2].id==3&&a[3].id==1) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p2.x, p2.y, p3.x, p3.y, p.x, p.y);
            }
            if(a[1].id==3&&a[2].id==1&&a[3].id==2) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p3.x, p3.y, p.x, p.y, p2.x, p2.y);
            }
            if(a[1].id==3&&a[2].id==2&&a[3].id==1) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p3.x, p3.y, p2.x, p2.y, p.x, p.y);
            }
        } else {
            //cout<<"~~~"<<endl;
            //cout<<a[1].id<<' '<<a[2].id<<' '<<a[3].id<<endl;
            //cout<<p4.x<<' '<<p4.y<<' '<<p3.x<<' '<<p3.y<<endl;
            if (a[1].id == 1 && a[2].id == 2 && a[3].id == 3) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p.x, p.y, p2.x, p2.y, p4.x, p4.y);
            }
            if (a[1].id == 1 && a[2].id == 3 && a[3].id == 2) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p2.x, p2.y, p.x, p.y, p4.x, p4.y);
            }
            if (a[1].id == 2 && a[2].id == 1 && a[3].id == 3) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p.x, p.y, p4.x, p4.y, p2.x, p2.y);
            }
            if (a[1].id == 2 && a[2].id == 3 && a[3].id == 1) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p2.x, p2.y, p4.x, p4.y, p.x, p.y);
            }
            if (a[1].id == 3 && a[2].id == 1 && a[3].id == 2) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p4.x, p4.y, p.x, p.y, p2.x, p2.y);
            }
            if (a[1].id == 3 && a[2].id == 2 && a[3].id == 1) {//321
                printf("%.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n", p4.x, p4.y, p2.x, p2.y, p.x, p.y);
            }
        }
    }

    return 0;
}
/*
4
24 16 20 25 15
16 24 15 20 25
1 1 1 1 1
50 50 1 2 3
18 5 102 86 59
0.0000000000 0.0000000000 7.0000000000 24.0000000000 14.0400000000 5.2800000000
6
26 29 34 27 17
36 11 32 18 21
13 3 7 3 6
2 38 5 4 4
32 42 16 7 12
8 33 5 4 2

20
1 28 22 19 21
19 41 25 22 20
17 41 3 2 2
11 8 10 4 8
44 21 4 3 2
9 1 3 2 2
11 20 11 8 9
12 3 8 6 6
28 47 3 2 2
49 32 38 21 31
12 9 10 4 7
19 13 13 6 10
7 22 19 14 6
1 48 39 30 19
4 16 9 2 8
17 43 17 14 5
42 22 42 40 36

*/