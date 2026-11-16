#include <stdio.h>
#include <time.h>

unsigned long long calls = 0;
unsigned long long memo[51] = {0};
int visited[51] = {0};

// Recursive Fibonacci function
unsigned long long fibonacci(int n) {
    calls++;

    if (n <= 1)
        return n;

    if (visited[n])
        return memo[n];

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    visited[n] = 1;

    return memo[n];
}

int main() {
    int n, i;
    unsigned long long a = 0, b = 1, c;
    clock_t start, end;
    double iterativeTime, recursiveTime;

    printf("Enter N: ");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Invalid input! Enter N between 1 and 50.");
        return 0;
    }

    // Iterative method
    start = clock();

    printf("Iterative: ");

    a = 0;
    b = 1;

    for (i = 0; i < n; i++) {
        printf("%llu ", a);

        c = a + b;
        a = b;
        b = c;
    }

    end = clock();
    iterativeTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    // Recursive method
    start = clock();

    printf("\nRecursive: ");

    for (i = 0; i < n; i++) {
        printf("%llu ", fibonacci(i));
    }

    end = clock();
    recursiveTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    printf("\nRecursive Calls: %llu", calls);
    printf("\nIterative Time: %.3f ms", iterativeTime);
    printf("\nRecursive Time: %.3f ms", recursiveTime);

    return 0;
}
