//
// Created by 赵婉如 on 2019-08-10.
//
struct Point
{
    int d[6],mx[6],mn[6];
    int l,r;
    int& operator [](int s)
    {return d[s];}
    void clear()
    {
        for(int i = 0;i<6;i++)
            d[i] = mn[i] = mx[i] = 0;
    }
}t[N],poi[N],target;
int cnt;
bool operator <(Point a,Point b)
{return a[D]<b[D];}
inline int getdis(Point a,Point b)
{
    int ans = 0;
    for(int i = 0;i<6;i++)
        ans = ans+(a[i]-b[i])*(a[i]-b[i]);
    return ans;
}
int top;
struct Heap
{
    int id,dis;
    Heap(){}
    Heap(int _id,int _dis):id(_id),dis(_dis){}
    bool operator <(const Heap &s){return dis<s.dis;}
}heap[20];
inline void clear()
{
    target.clear();
    for(int i = 1;i<= cnt;i++)
        t[i].clear();
    cnt = 0;
}
inline void Max(int &x,int y){x = x>y?x:y;}
inline void Min(int &x,int y){x = x<y?x:y;}
inline void Push_up(int p)
{
    Point ls = t[t[p].l],rs = t[t[p].r];
    for(int i = 0;i<6;i++)
    {
        if(t[p].l)Max(t[p].mx[i],ls.mx[i]),Min(t[p].mn[i],ls.mn[i]);
        if(t[p].r)Max(t[p].mx[i],rs.mx[i]),Min(t[p].mn[i],rs.mn[i]);
    }
}
inline int getmindis(int k,Point p)
{
    int ans = 0;
    for(int i = 0;i<6;i++)
    {
        if(p[i]>t[k].mx[i])
            ans = ans+(p[i]-t[k].mx[i])*(p[i]-t[k].mx[i]);
        if(p[i]<t[k].mn[i])
            ans = ans+(t[k].mn[i]-p[i])*(t[k].mn[i]-p[i]);
    }
    return ans;
}
int build(int l,int r,int o)
{
    if(l>r)return 0;
    D = o;
    int mid = (l+r)>>1;
    nth_element(poi+l,poi+mid,poi+r+1);
    t[mid] = poi[mid];
    for(int i= 0;i<k;i++)
        t[mid].mx[i]=t[mid].mn[i]=t[mid][i];
    t[mid].l = build(l,mid-1,(o+1)%k);
    t[mid].r = build(mid+1,r,(o+1)%k);
    Push_up(mid);
    return mid;
}
void solve(int o)
{
    int d,dl = INF,dr = INF;
    d = getdis(t[o],target);
    if(d<heap[1].dis)
    {
        pop_heap(heap+1,heap+top+1);
        heap[top] = Heap(o,d);
        push_heap(heap+1,heap+1+top);
    }
    dl = getmindis(t[o].l,target);
    dr = getmindis(t[o].r,target);
    if(dl>dr)
    {
        if(dl<heap[1].dis)solve(t[o].l);
        if(dr<heap[1].dis)solve(t[o].r);
    }else
    {
        if(dr<heap[1].dis)solve(t[o].r);
        if(dl<heap[1].dis)solve(t[o].l);
    }
}