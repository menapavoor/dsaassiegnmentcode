#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];

// insert using quadratic probing
void insert(int key, int m)
{
    int i = 0;
    int index;

    while(i < m)
    {
        index = (key % m + i*i) % m;

        if(table[index] == -1)
        {
            table[index] = key;
            return;
        }

        i++;
    }
}

// search using quadratic probing
int search(int key, int m)
{
    int i = 0;
    int index;

    while(i < m)
    {
        index = (key % m + i*i) % m;

        if(table[index] == key)
            return 1;

        if(table[index] == -1)
            return 0;

        i++;
    }

    return 0;
}

int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    // initialize table
    for(int i = 0; i < m; i++)
        table[i] = -1;

    char op[10];
    int x;

    for(int i = 0; i < n; i++)
    {
        scanf("%s %d", op, &x);

        if(strcmp(op, "INSERT") == 0)
            insert(x, m);

        else if(strcmp(op, "SEARCH") == 0)
        {
            if(search(x, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}