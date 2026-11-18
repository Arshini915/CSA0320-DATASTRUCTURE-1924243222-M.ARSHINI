#include <stdio.h>

int main()
{
    int a[] = {10, 9, 7, 4, 3, 1, 2};
    int n = 7, i, j, found;

    printf("Missing elements: ");

    for(i = 1; i <= 10; i++)
    {
        found = 0;

        for(j = 0; j < n; j++)
        {
            if(a[j] == i)
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
            printf("%d ", i);
    }

    return 0;
}
