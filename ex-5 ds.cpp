#include <stdio.h>

int main() {
    int n, i;
    int a = 0, b = 1, c;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid input");
        return 0;
    }

    printf("Fibonacci series: ");

    for (i = 1; i <= n; i++) {
        printf("%d", a);

        if (i < n)
            printf(" ");

        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}
