#include <stdio.h>

#define MAX 100

// check if possible within maxTime
int isPossible(int arr[], int n, int k, int maxTime)
{
    int painters = 1;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(sum + arr[i] <= maxTime)
        {
            sum += arr[i];
        }
        else
        {
            painters++;
            sum = arr[i];

            if(painters > k)
                return 0;
        }
    }

    return 1;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    int max = 0, sum = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        if(arr[i] > max)
            max = arr[i];

        sum += arr[i];
    }

    int low = max;
    int high = sum;
    int ans = sum;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}