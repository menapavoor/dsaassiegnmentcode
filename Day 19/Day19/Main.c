#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Sort the array
    qsort(nums, n, sizeof(int), cmp);
        

    int left = 0, right = n - 1;
    int minSum = __INT_MAX__;
    int ans1 = nums[left], ans2 = nums[right];

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            ans1 = nums[left];
            ans2 = nums[right];
        }

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    printf("%d %d\n", ans1, ans2);
    return 0;
}