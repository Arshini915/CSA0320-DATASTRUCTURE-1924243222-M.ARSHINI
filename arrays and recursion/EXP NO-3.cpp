
#include <stdio.h>

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

int main()
{
    int arr[10], original[10];
    int i, k, sum1 = 0, sum2 = 0;
    char choice, again;

    printf("Enter 10 numbers: ");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        original[i] = arr[i];
        sum1 += arr[i];
    }

    do
    {
        printf("Rotate Left (L)/Right (R): ");
        scanf(" %c", &choice);

        printf("By positions: ");
        scanf("%d", &k);

        if(k < 0 || k >= 10)
        {
            printf("Invalid K! Enter K between 0 and 9.\n");
            continue;
        }

        printf("Original: ");
        display(arr, 10);

        if(choice == 'L' || choice == 'l')
        {
            reverse(arr, 0, k - 1);
            printf("Step1: Reverse 0-%d -> ", k - 1);
            display(arr, 10);

            reverse(arr, k, 9);
            printf("Step2: Reverse %d-9 -> ", k);
            display(arr, 10);

            reverse(arr, 0, 9);
            printf("Step3: Reverse all -> ");
            display(arr, 10);
        }
        else if(choice == 'R' || choice == 'r')
        {
            reverse(arr, 0, 9 - k);
            printf("Step1: Reverse 0-%d -> ", 9 - k);
            display(arr, 10);

            reverse(arr, 10 - k, 9);
            printf("Step2: Reverse %d-9 -> ", 10 - k);
            display(arr, 10);

            reverse(arr, 0, 9);
            printf("Step3: Reverse all -> ");
            display(arr, 10);
        }
        else
        {
            printf("Invalid rotation direction!\n");
            continue;
        }

        sum2 = 0;
        for(i = 0; i < 10; i++)
            sum2 += arr[i];

        printf("Sum difference: %d\n", sum2 - sum1);

        printf("Do you want another rotation? (Y/N): ");
        scanf(" %c", &again);

    } while(again == 'Y' || again == 'y');

    return 0;
}
