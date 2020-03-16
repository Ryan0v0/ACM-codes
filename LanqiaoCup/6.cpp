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
bool check(char c)
{
    return (c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u');
}
string str;
int state;
int main()
{
    cin >> str;
    state = 1;
    bool ok = true;
    for (char c : str) {
        // cout << c << "***" << endl;
        if (!check(c)) {
            if (state == 1 || state == 3) state = state;
            else if (state == 2) state = 3;
            else {
                ok = false;
                break;
            }
        } else {
            if (state == 1) state = 2;
            else if (state == 3) state = 4;
            else if (state == 2|| state == 4) state = state;
            else {
                ok = false;
                break;
            }
        }
        // cout << c << ' ' << state << endl;
    }
    if ((!ok) || state != 4) puts("no");
    else puts("yes");
    return 0;
}