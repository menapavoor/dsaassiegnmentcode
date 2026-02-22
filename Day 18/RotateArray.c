#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);
    k = k % n;

    // reverse helper
    void reverse(int* arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    // rotate using reverse method
    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    free(nums);
    return 0;
}