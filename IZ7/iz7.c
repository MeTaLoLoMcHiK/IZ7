#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
struct Student {
    char name[NAME_LENGTH];  
    int birth_year;          
    int course;              
    float avg_grade;         
};

void input_students(struct Student students[], int n);
void print_students(struct Student students[], int n);

int compare_by_name(const void* a, const void* b) {
    return strcmp(((struct Student*)a)->name, ((struct Student*)b)->name);
}

int compare_by_birth_year(const void* a, const void* b) {
    return ((struct Student*)a)->birth_year - ((struct Student*)b)->birth_year;
}

int compare_by_course(const void* a, const void* b) {
    return ((struct Student*)a)->course - ((struct Student*)b)->course;
}

int compare_by_avg_grade(const void* a, const void* b) {
    if (((struct Student*)a)->avg_grade < ((struct Student*)b)->avg_grade) return -1;
    if (((struct Student*)a)->avg_grade > ((struct Student*)b)->avg_grade) return 1;
    return 0;
}


void input_students(struct Student students[], int n) {
    setlocale(LC_ALL, "RU");
    for (int i = 0; i < n; i++) {
        printf("������� ���������� � �������� %d:\n", i + 1);
        printf("���: ");
        fgets(students[i].name, NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; 

        printf("��� ��������: ");
        if (scanf("%d", &students[i].birth_year) != 1) {
            printf("������ �����!\n");
            return;
        }

        printf("����: ");
        if (scanf("%d", &students[i].course) != 1) {
            printf("������ �����!\n");
            return;
        }

        printf("������� ����: ");
        if (scanf("%f", &students[i].avg_grade) != 1) {
            printf("������ �����!\n");
            return;
        }

        getchar();
    }
}
void print_students(struct Student students[], int n) {
    setlocale(LC_ALL, "RU");
    printf("\n������ ���������:\n");
    for (int i = 0; i < n; i++) {
        printf("���: %s, ��� ��������: %d, ����: %d, ������� ����: %.2f\n",
            students[i].name, students[i].birth_year, students[i].course, students[i].avg_grade);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    struct Student students[MAX_STUDENTS];
    int n;

    printf("������� ���������� ���������: ");
    if (scanf("%d", &n) != 1) {
        printf("������ �����!\n");
        return 1;
    }
    getchar(); 
    input_students(students, n);

    printf("\n����� ����������:\n");
    printf("1 - �� �����\n");
    printf("2 - �� ���� ��������\n");
    printf("3 - �� �����\n");
    printf("4 - �� �������� �����\n");
    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("������ �����!\n");
        return 1;
    }
    getchar(); 
    switch (choice) {
    case 1:
        qsort(students, n, sizeof(struct Student), compare_by_name);
        break;
    case 2:
        qsort(students, n, sizeof(struct Student), compare_by_birth_year);
        break;
    case 3:
        qsort(students, n, sizeof(struct Student), compare_by_course);
        break;
    case 4:
        qsort(students, n, sizeof(struct Student), compare_by_avg_grade);
        break;
    default:
        printf("�������� �����!\n");
        return 1;
    }

    print_students(students, n);

    return 0;
}
