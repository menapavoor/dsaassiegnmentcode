#include <stdio.h>

#define MAX 1000

int main()
{
    int n;
    scanf("%d", &n);

    int arr[MAX];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // find max
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];

    int count[max + 1];

    // initialize count array
    for(int i = 0; i <= max; i++)
        count[i] = 0;

    // frequency
    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    // prefix sum
    for(int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[MAX];

    // build output (reverse for stability)
    for(int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // print sorted array
    for(int i = 0; i < n; i++)
        printf("%d ", output[i]);

    return 0;
}