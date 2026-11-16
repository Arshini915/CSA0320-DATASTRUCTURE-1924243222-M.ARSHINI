
#include <stdio.h>

struct Triple {
    int row, col, value;
};

int main() {
    struct Triple A[100], B[100], C[200];
    int r1, c1, n1, r2, c2, n2;
    int i, j, k = 0;

    // Read first matrix
    scanf("%d %d %d", &r1, &c1, &n1);

    for (i = 0; i < n1; i++) {
        scanf("%d %d %d",
              &A[i].row, &A[i].col, &A[i].value);
    }

    // Read second matrix
    scanf("%d %d %d", &r2, &c2, &n2);

    for (i = 0; i < n2; i++) {
        scanf("%d %d %d",
              &B[i].row, &B[i].col, &B[i].value);
    }

    if (r1 != r2 || c1 != c2) {
        printf("Matrix dimensions must be equal");
        return 0;
    }

    // Add sparse matrices
    i = 0;
    j = 0;

    while (i < n1 && j < n2) {
        if (A[i].row < B[j].row ||
           (A[i].row == B[j].row &&
            A[i].col < B[j].col)) {
            C[k++] = A[i++];
        }
        else if (B[j].row < A[i].row ||
                (B[j].row == A[i].row &&
                 B[j].col < A[i].col)) {
            C[k++] = B[j++];
        }
        else {
            int sum = A[i].value + B[j].value;

            if (sum != 0) {
                C[k] = A[i];
                C[k].value = sum;
                k++;
            }

            i++;
            j++;
        }
    }

    while (i < n1)
        C[k++] = A[i++];

    while (j < n2)
        C[k++] = B[j++];

    // Display dense matrix
    int matrix[10][10] = {0};

    for (i = 0; i < k; i++) {
        matrix[C[i].row][C[i].col] = C[i].value;
    }

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
