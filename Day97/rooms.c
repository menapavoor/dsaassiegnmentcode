#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// structure for meeting
typedef struct {
    int start, end;
} Meeting;

// sort by start time
int compare(const void *a, const void *b)
{
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->start - m2->start;
}

// min heap (simple array version)
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// heapify up
void heapifyUp(int heap[], int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;
        if(heap[parent] <= heap[index])
            break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

// heapify down
void heapifyDown(int heap[], int size, int index)
{
    int smallest = index;

    while(1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index)
        {
            swap(&heap[smallest], &heap[index]);
            index = smallest;
        }
        else
            break;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Meeting arr[MAX];

    for(int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    // sort meetings
    qsort(arr, n, sizeof(Meeting), compare);

    int heap[MAX];
    int size = 0;

    // first meeting
    heap[size++] = arr[0].end;

    for(int i = 1; i < n; i++)
    {
        // if room free
        if(arr[i].start >= heap[0])
        {
            heap[0] = arr[i].end;
            heapifyDown(heap, size, 0);
        }
        else
        {
            // new room
            heap[size] = arr[i].end;
            heapifyUp(heap, size);
            size++;
        }
    }

    printf("%d\n", size);

    return 0;
}