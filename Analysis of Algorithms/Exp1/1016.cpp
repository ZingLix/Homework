//HDOJ 2007
#include <iostream>
#include <cmath>
#include <cstdio>

int main() {
    int x, y;
    while(~scanf("%d %d", &x, &y)) {
        if(x > y) std::swap(x, y);
        int sum_odd = 0, sum_even = 0;
        for(int i = x; i <= y; ++i) {
            if(i % 2 == 0) {
                sum_even += i * i;
            } else {
                sum_odd += i * i * i;
            }
        }
        printf("%d %d\n", sum_even, sum_odd);
    }
}