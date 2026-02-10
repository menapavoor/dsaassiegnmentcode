#include <stdio.h>

long long power(long long a, long long b) {
    if (b == 0)
        return 1;              // Base case: a^0 = 1
    return a * power(a, b - 1); // Recursive step
}

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    printf("%lld", power(a, b));
    return 0;
}