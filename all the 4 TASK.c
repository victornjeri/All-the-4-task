Here are the C program solutions for each of the tasks:
#victor nganga njeri
#CT/102/G/23877/24
### Task 1: Store Information of 5 Students

c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    struct Student students[5];
    FILE *file = fopen("students.txt", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);

        fprintf(file, "Name: %s, Marks: %d\n", students[i].name, students[i].marks);
    }

    fclose(file);
    return 0;
}


### Task 2: Store Information of n Students in Append Mode

c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    FILE *file = fopen("students.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);

        fprintf(file, "Name: %s, Marks: %d\n", students[i].name, students[i].marks);
    }

    fclose(file);
    return 0;
}


### Task 3: Use fwrite() and Read Back Data

c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    struct Student students[5];
    FILE *file = fopen("students.dat", "wb");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }

    fwrite(students, sizeof(struct Student), 5, file);
    fclose(file);

    file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fread(students, sizeof(struct Student), 5, file);
    fclose(file);

    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
    }

    return 0;
}


These programs:
- For Task 1: Read and write data for 5 students to a text file.
- For Task 2: Read and append data for n students to the same text file.
- For Task 3: Use binary I/O to write and read student data from a file using fwrite() and fread().