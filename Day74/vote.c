#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main()
{
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];

    for(int i = 0; i < n; i++)
        scanf("%s", names[i]);

    int maxVotes = 0;
    char winner[LEN] = "";

    for(int i = 0; i < n; i++)
    {
        int count = 1;

        // count frequency of names[i]
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(names[i], names[j]) == 0)
                count++;
        }

        // update winner
        if(count > maxVotes)
        {
            maxVotes = count;
            strcpy(winner, names[i]);
        }
        else if(count == maxVotes)
        {
            if(strcmp(names[i], winner) < 0)
                strcpy(winner, names[i]);
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}