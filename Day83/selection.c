#include <stdio.h>

#define MAX 1000

int main()
{
    int n;
    scanf("%d", &n);

    int arr[MAX];

    // input array
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // selection sort
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // output sorted array
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}