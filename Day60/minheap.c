#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int isMinHeap = 1;

    for(int i = 0; i <= (n - 2) / 2; i++)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[i] > arr[left])
        {
            isMinHeap = 0;
            break;
        }

        if(right < n && arr[i] > arr[right])
        {
            isMinHeap = 0;
            break;
        }
    }

    if(isMinHeap)
        printf("YES");
    else
        printf("NO");

    return 0;
}