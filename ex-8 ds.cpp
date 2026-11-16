#include <stdio.h>

int main() {
    int a[100], n, i, j, max = 0, found;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] > max) {
            max = a[i];
        }
    }

    printf("Missing elements: ");

    for (i = 1; i <= max; i++) {
        found = 0;

        for (j = 0; j < n; j++) {
            if (a[j] == i) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}
