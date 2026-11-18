#include <stdio.h>
#include <time.h>

int calls = 0;

int fibonacci(int n)
{
    calls++;

    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, i, a = 0, b = 1, c;

    clock_t start, end;
    double iterativeTime, recursiveTime;

    printf("Enter N: ");
    scanf("%d", &n);

    if(n < 1 || n > 30)
    {
        printf("Invalid input!");
        return 0;
    }

    start = clock();

    printf("Iterative: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", a);

        c = a + b;
        a = b;
        b = c;
    }

    end = clock();
    iterativeTime = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

    calls = 0;

    start = clock();

    printf("\nRecursive: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    end = clock();
    recursiveTime = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

    printf("\nRecursive Calls: %d", calls);
    printf("\nIterative Time: %.3f ms", iterativeTime);
    printf("\nRecursive Time: %.3f ms", recursiveTime);

    return 0;
}
