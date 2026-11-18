
#include <stdio.h>

int main()
{
    int a[100][3], b[100][3], c[100][3];
    int mat[10][10] = {0};
    int r1, c1, r2, c2;
    int n1, n2, n3 = 0;
    int i, j;

    // Read Matrix 1
    scanf("%d %d %d", &r1, &c1, &n1);

    for(i = 0; i < n1; i++)
    {
        scanf("%d %d %d",
              &a[i][0], &a[i][1], &a[i][2]);
    }

    // Read Matrix 2
    scanf("%d %d %d", &r2, &c2, &n2);

    for(i = 0; i < n2; i++)
    {
        scanf("%d %d %d",
              &b[i][0], &b[i][1], &b[i][2]);
    }

    if(r1 != r2 || c1 != c2 ||
       r1 > 10 || c1 > 10 ||
       r1 < 1 || c1 < 1)
    {
        printf("Invalid matrix dimensions!");
        return 0;
    }

    // Add Matrix 1 elements
    for(i = 0; i < n1; i++)
        mat[a[i][0]][a[i][1]] += a[i][2];

    // Add Matrix 2 elements
    for(i = 0; i < n2; i++)
        mat[b[i][0]][b[i][1]] += b[i][2];

    // Store result in triplet form
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            if(mat[i][j] != 0)
            {
                c[n3][0] = i;
                c[n3][1] = j;
                c[n3][2] = mat[i][j];
                n3++;
            }
        }
    }

    // Display dense matrix
    printf("Sum Dense Matrix:\n");

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
