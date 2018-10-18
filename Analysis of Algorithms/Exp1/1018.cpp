//HDOJ 1406
#include <iostream>
#include <cstdio>

bool check(int n) {
    int sum = 0;
    for(int i = 1; i < n; ++i) {
        if(n % i == 0) sum += i;
    }
    return sum == n;
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int lower_bound, upper_bound;
        scanf("%d %d", &lower_bound, &upper_bound);
        if(lower_bound > upper_bound) std::swap(lower_bound, upper_bound);
        int cnt = 0;
        for(int i = lower_bound; i <= upper_bound; ++i) {
            if(check(i)) ++cnt;

        }
        printf("%d\n", cnt);

    }
    return 0;
}