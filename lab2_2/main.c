/*
 * Лабораторная работа №2.
 *
 * Вариант П1: Повернуть квадратную матрицу 
 * на 90 градусов по часовой стрелке.
 *
 * Автор: Ефимов Михаил Егорович ПИ-11БО
 */

#include <stdio.h>

#define MAX_SIZE 20

/*creating function prototypes*/
int input_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int m);
void transpose_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int m);
void reverse_row_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int m);
void rotate_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int m);
void print_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int m);

int main(void)
{
    int array[MAX_SIZE][MAX_SIZE];
    int n, m;
    /* processing size input */
    printf("Enter number of strings and column greater/equal then 1 and lower/equal then 20\n");
    if (scanf_s("%d %d", &n, &m) == 2) {
        if (1 <= n <= MAX_SIZE && 1 <= m <= MAX_SIZE) {
            puts("Enter each element of the array\n");
            /* filling the matrix */
            if (input_matrix(array, n, m) == 1) {
                puts("Invalid input: The numbers must be integer\n");
                return 1;
            }
        }
        else {
            puts("Invalid input: The numbers must be between 1 and 20\n");
            return 1;
        }
    }
    else {
        puts("Invalid input: The numbers must be integer\n");
        return 1;
    }
    /* calling main proccesing function*/
    rotate_matrix(array, n, m);
    /* printing result matrix*/
    puts("Result Matrix: ");
    print_matrix(array, n, m);
    return 0;
}

int input_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf_s("%d", &a[i][j]) != 1) {
                return 1;
            }
        }
    }
    return 0;
}

void transpose_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

void reverse_row_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            int buffer = a[i][j];
            a[i][j] = a[i][m - 1 - j];
            a[i][m - 1 - j] = buffer;
        }
    }
}

void rotate_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
    transpose_matrix(a, n, m);
    reverse_row_matrix(a, n, m);
}

void print_matrix(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
    puts("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%-4d", a[i][j]);
        }
        puts("\n");
    }
}