#include <stdio.h>

#define SIZE 10

void display(int arr[], int n)
{
    int i;
    printf("[");
    for(i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if(i < n - 1)
            printf(" ");
    }
    printf("]\n");
}

void reverse(int arr[], int start, int end)
{
    int temp;

    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int arr[SIZE], original[SIZE];
    int i, k, n = SIZE;
    int sum1 = 0, sum2 = 0;
    char choice, again;

    printf("Enter 10 numbers: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        original[i] = arr[i];
    }

    do
    {
        printf("\nRotate Left(L)/Right(R): ");
        scanf(" %c", &choice);

        printf("By positions: ");
        scanf("%d", &k);

        if(k < 0 || k >= n)
        {
            printf("Invalid K! Enter K between 0 and 9.\n");
            continue;
        }

        printf("\nOriginal: ");
        display(arr, n);

        if(choice == 'L' || choice == 'l')
        {
            reverse(arr, 0, k - 1);
            printf("Step1: Reverse 0-%d -> ", k - 1);
            display(arr, n);

            reverse(arr, k, n - 1);
            printf("Step2: Reverse %d-%d -> ", k, n - 1);
            display(arr, n);

            reverse(arr, 0, n - 1);
            printf("Step3: Reverse all -> ");
            display(arr, n);
        }
        else if(choice == 'R' || choice == 'r')
        {
            reverse(arr, 0, n - k - 1);
            printf("Step1: Reverse 0-%d -> ", n-k-1);
            display(arr, n);

            reverse(arr, n-k, n-1);
            printf("Step2: Reverse %d-%d -> ", n-k, n-1);
            display(arr, n);

            reverse(arr, 0, n-1);
            printf("Step3: Reverse all -> ");
            display(arr, n);
        }
        else
        {
            printf("Invalid rotation choice!\n");
            continue;
        }

        printf("\nDo you want another rotation? (Y/N): ");
        scanf(" %c", &again);

    } while(again == 'Y' || again == 'y');

    for(i = 0; i < n; i++)
    {
        sum1 += original[i];
        sum2 += arr[i];
    }

    printf("\nFinal Rotated Array: ");
    display(arr, n);

    printf("Sum Difference: %d\n", sum1 - sum2);

    return 0;
}
