#include <stdio.h>

#define MAX 1000

int main()
{
    int n;
    scanf("%d", &n);

    int arr[MAX];

    // input
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // insertion sort
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    // output
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}