/*
 * Лабораторная работа №2.
 *
 * Вариант 17: найти столбец с максимальнным
 * количеством положительныых элементов
 * и вывести на экран его номер и
 * соответствующее количество.
 *
 * Автор: Утников Александр Евгеньевич ПИ-11БО
 */

#include <stdio.h>

#define MAX_SIZE 20
#define MIN_SIZE 1

int input_matrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int m);
void find_max_pos(int matrix[MAX_SIZE][MAX_SIZE], int n, int m,
                  int *ret_col_max_pos_count, int *ret_max_pos_count);
void print_result(int col_max_pos_count, int max_pos_count);
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int m);

int main(void) {
  int n, m;
  printf("Enter matrix size (NxM): ");

  // processing size input
  if (scanf("%d %d", &n, &m) != 2) {
    printf("You must enter two numbers.\n");
    return 1;
  }

  if (n < MIN_SIZE || n > MAX_SIZE || m < MIN_SIZE || m > MAX_SIZE) {
    printf("The matrix size must be in the range 1–20\n");
    return 1;
  }

  // filling the matrix
  int matrix[MAX_SIZE][MAX_SIZE];
  printf("Enter the values for the matrix:\n");
  if (input_matrix(matrix, n, m) != 0) {
    return 1;
  }

  printf("\nInput matrix:\n");
  print_matrix(matrix, n, m);

  // find the column with the maximum
  // number of positive elements
  int col_max_pos_count;
  int max_pos_count;
  find_max_pos(matrix, n, m, &col_max_pos_count, &max_pos_count);

  print_result(col_max_pos_count, max_pos_count);

  return 0;
}

int input_matrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (scanf("%d", &matrix[i][j]) != 1) {
        printf("You have to enter a number.\n");
        return 1;
      }
    }
  }
  return 0;
}

void find_max_pos(int matrix[MAX_SIZE][MAX_SIZE], int n, int m,
                  int *ret_col_max_pos_count, int *ret_max_pos_count) {
  int max_pos_count = -1;
  int col_max_pos_count = -1;

  // swap i and j
  // iterate over the columns
  for (int j = 0; j < m; j++) {
    int cur_pos_count = 0;
    for (int i = 0; i < n; i++) {
      if (matrix[i][j] > 0) {
        cur_pos_count++;
      }
    }

    // Last pos. col. goes to the answer. > for first col.
    if (cur_pos_count >= max_pos_count && cur_pos_count > 0) {
      max_pos_count = cur_pos_count;
      col_max_pos_count = j + 1;
    }
  }

  *ret_col_max_pos_count = col_max_pos_count;
  *ret_max_pos_count = max_pos_count;
}

void print_result(int col_max_pos_count, int max_pos_count) {
  if (col_max_pos_count == -1) {
    printf("No positive numbers in matrix.\n");
    return;
  }
  printf("Column: %d (%d positive elements)\n", col_max_pos_count,
         max_pos_count);
  return;
}

void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}
