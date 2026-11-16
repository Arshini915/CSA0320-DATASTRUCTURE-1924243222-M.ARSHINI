
#include <stdio.h>

int main() {
    int a[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(a) / sizeof(a[0]);

    if (n >= 5) {
        printf("%d", a[4]);
    } else {
        printf("Array does not contain 5 elements");
    }

    return 0;
}
