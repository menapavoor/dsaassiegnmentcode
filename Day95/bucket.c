#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// insertion sort for bucket
void insertionSort(float arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    float arr[MAX];

    for(int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    // create buckets
    float buckets[MAX][MAX];
    int count[MAX] = {0};

    for(int i = 0; i < n; i++)
    {
        int index = n * arr[i]; // bucket index
        buckets[index][count[index]++] = arr[i];
    }

    // sort each bucket
    for(int i = 0; i < n; i++)
    {
        if(count[i] > 0)
            insertionSort(buckets[i], count[i]);
    }

    // concatenate buckets
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            arr[k++] = buckets[i][j];
        }
    }

    // print sorted array
    for(int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}