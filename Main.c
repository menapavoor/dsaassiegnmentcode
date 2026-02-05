#include <stdio.h>

int main() {
<<<<<<< HEAD
    int n, pos;
    scanf("%d", &n);

    int arr[n];
=======
    int n, pos, x;
    scanf("%d", &n);

    int arr[n + 1];  // allocate space for n+1 elements

>>>>>>> 8b39f04a6524667c83a5717cd20ddeaa408b6153
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

<<<<<<< HEAD
    scanf("%d", &pos);  // 1-based position

    // Shift elements left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array (n-1 elements)
    for (int i = 0; i < n - 1; i++) {
=======
    scanf("%d", &pos);
    scanf("%d", &x);

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert x at position pos (1-based)
    arr[pos - 1] = x;

    // Print updated array
    for (int i = 0; i <= n; i++) {
>>>>>>> 8b39f04a6524667c83a5717cd20ddeaa408b6153
        printf("%d ", arr[i]);
    }

    return 0;
}