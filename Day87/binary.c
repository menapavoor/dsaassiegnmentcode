#include <stdio.h>

#define MAX 1000

// simple sort (for safety)
void sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// binary search
int binarySearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == x)
            return mid;
        else if(arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, x;
    scanf("%d", &n);

    int arr[MAX];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &x);

    sort(arr, n);

    int result = binarySearch(arr, n, x);

    // print sorted array
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    // print result
    printf("%d\n", result);

    return 0;
}