#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int start, end;
} Interval;

// sort by start time
int compare(const void *a, const void *b)
{
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return i1->start - i2->start;
}

int main()
{
    int n;
    scanf("%d", &n);

    Interval arr[MAX];

    for(int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    // sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    Interval result[MAX];
    int index = 0;

    // first interval
    result[index++] = arr[0];

    for(int i = 1; i < n; i++)
    {
        // overlap
        if(arr[i].start <= result[index - 1].end)
        {
            if(arr[i].end > result[index - 1].end)
                result[index - 1].end = arr[i].end;
        }
        else
        {
            result[index++] = arr[i];
        }
    }

    // print result
    for(int i = 0; i < index; i++)
        printf("%d %d\n", result[i].start, result[i].end);

    return 0;
}