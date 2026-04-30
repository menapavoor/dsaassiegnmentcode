#include <stdio.h>

#define MAX 1000

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0, maxLen = 0;

    // hash array (store first index of sum)
    int hash[2 * MAX + 1];

    for(int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -1;

    hash[MAX] = -2; // sum = 0 at index -1

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        int index = sum + MAX;

        if(hash[index] != -1)
        {
            int len = i - hash[index];
            if(len > maxLen)
                maxLen = len;
        }
        else
        {
            hash[index] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}