
#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

int main()
{
    struct Student s[100];
    FILE *fp;
    int n, i, highest = 0;
    float sum = 0, average;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if(n < 1 || n > 100)
    {
        printf("Invalid number of students!");
        return 0;
    }

    fp = fopen("students.txt", "w");

    if(fp == NULL)
    {
        printf("File cannot be opened!");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        scanf("%d %49s %f", &s[i].roll,
              s[i].name, &s[i].marks);

        fprintf(fp, "%d %s %.2f\n",
                s[i].roll, s[i].name, s[i].marks);

        sum += s[i].marks;

        if(s[i].marks > s[highest].marks || i == 0)
            highest = i;
    }

    fclose(fp);

    average = sum / n;

    printf("Highest Mark: %.0f (%s)\n",
           s[highest].marks, s[highest].name);

    printf("Class Average: %.2f\n", average);

    printf("%d records stored successfully.\n", n);

    return 0;
}
