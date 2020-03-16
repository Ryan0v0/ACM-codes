#include <bits/stdc++.h>
using namespace std;
int main() {
    int cnt = 0;
    for (int i = 1; i < sqrt(1200000); i++) {
        if (1200000 % i == 0) cnt+=2;
    }
    cout << cnt << endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}