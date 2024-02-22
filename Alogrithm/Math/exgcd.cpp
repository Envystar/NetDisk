#include <bits/stdc++.h>

void exgcd(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = 1, y = 0;
    } else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

int main() {
    int x, y;
    exgcd(3, 2, x, y);
    std::cout << x << " " <<  y;
    return 0;
}