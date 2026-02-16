#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Print the first element (always unique)
    printf("%d", nums[0]);

    // Print only when the current element differs from the previous one
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            printf(" %d", nums[i]);
        }
    }

    return 0;
}