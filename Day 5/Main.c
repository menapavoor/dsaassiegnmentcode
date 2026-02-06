#include <stdio.h>

int main() {
    int p;
    scanf("%d", &p);

    int a[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    int q;
    scanf("%d", &q);

    int b[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    // Merge and print directly
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    // Print remaining elements from a
    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }

    // Print remaining elements from b
    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}