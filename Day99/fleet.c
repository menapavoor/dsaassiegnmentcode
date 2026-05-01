#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int pos;
    int speed;
} Car;

// sort by position descending
int compare(const void *a, const void *b)
{
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;
    return c2->pos - c1->pos;
}

int main()
{
    int n, target;
    scanf("%d", &n);

    int position[MAX], speed[MAX];

    for(int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    scanf("%d", &target);

    Car cars[MAX];

    for(int i = 0; i < n; i++)
    {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    // sort cars by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0;

    for(int i = 0; i < n; i++)
    {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if(time > lastTime)
        {
            fleets++;
            lastTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}