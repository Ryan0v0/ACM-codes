
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
stack<int> s;
stack<char> z;
int n,y;
char c[10];
bool can(char x)
{
    if(x=='x'||x=='/') return 1;
    return 0;
}
void f(char x)
{
    int a=s.top();
    s.pop();
    int b=s.top();
    s.pop();
    int y;
    switch(x)
    {
        case '+': y=a+b;break;
        case 'x': y=a*b;break;
        case '/': y=b/a;break;
    }
    s.push(y);
}
int main() {
    cin >> n;
    while (n--) {
        while (!s.empty()) s.pop();
        while (!z.empty()) z.pop();
        cin >> c;
        for (int i = 0; i < strlen(c); i++) {
            if (c[i] >= '0' && c[i] <= '9')
                s.push(c[i] - '0');
            else if (can(c[i])) {
                s.push(c[++i] - '0');
                f(c[i - 1]);
            } else if (c[i] == '-') {
                z.push('+');
                s.push((c[++i] - '0') * (-1));
            } else z.push(c[i]);
        }
        while (!z.empty()) {
            f(z.top());
            z.pop();
        }
        if (s.top() == 24)
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}