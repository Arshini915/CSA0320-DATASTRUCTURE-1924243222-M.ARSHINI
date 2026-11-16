#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    struct Student s[100];
    int n, i, highestIndex = 0;
    float sum = 0, average;
    FILE *fp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid number of students");
        return 0;
    }

    fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("File cannot be opened");
        return 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d %49s %f",
              &s[i].rollNo, s[i].name, &s[i].marks);

        sum += s[i].marks;

        if (s[i].marks > s[highestIndex].marks) {
            highestIndex = i;
        }

        fprintf(fp, "%d %s %.2f\n",
                s[i].rollNo, s[i].name, s[i].marks);
    }

    fclose(fp);

    average = sum / n;

    printf("Highest Mark: %.0f (%s)\n",
           s[highestIndex].marks,
           s[highestIndex].name);

    printf("Class Average: %.2f\n", average);

    printf("%d records stored successfully.", n);

    return 0;
}
