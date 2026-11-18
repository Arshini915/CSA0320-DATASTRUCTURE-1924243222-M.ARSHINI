#include <stdio.h>

int main()
{
    int n, i;
    int a = 0, b = 1, c;
    int fib[50], sum = 0, largest;

    printf("Enter number of terms (1-50): ");
    scanf("%d", &n);

    if(n < 1 || n > 50)
    {
        printf("Invalid input! Please enter terms between 1 and 50.");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        fib[i] = a;
        sum += a;

        c = a + b;
        a = b;
        b = c;
    }

    largest = fib[0];

    printf("Fibonacci Series: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", fib[i]);

        if(fib[i] > largest)
            largest = fib[i];
    }

    printf("\nSum of series: %d", sum);
    printf("\nLargest term: %d", largest);

    return 0;
}
