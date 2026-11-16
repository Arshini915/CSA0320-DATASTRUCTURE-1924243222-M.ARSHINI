
#include <stdio.h>

int main() {
    int n, i;
    int a = 0, b = 1, c;
    int sum = 0, largest = 0;

    printf("Enter number of terms (1-50): ");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Invalid input! Please enter terms between 1 and 50.");
        return 0;
    }

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; i++) {
        printf("%d", a);

        if (i < n)
            printf(" ");

        sum = sum + a;
        largest = a;

        c = a + b;
        a = b;
        b = c;
    }

    printf("\nSum of series: %d", sum);
    printf("\nLargest term: %d", largest);

    return 0;
}
