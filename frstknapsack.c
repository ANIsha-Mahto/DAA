#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int row, int column, int value[], int weight[], int knapsack_capacity) {
    int knapsack_matrix[row][column];
    int i,j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            if(i == 0 || j == 0) {
                knapsack_matrix[i][j] = 0;
            } else if(weight[i - 1] <= j) {
                knapsack_matrix[i][j] = max(knapsack_matrix[i - 1][j], value[i - 1] + knapsack_matrix[i - 1][j - weight[i - 1]]);
            } else {
                knapsack_matrix[i][j] = knapsack_matrix[i - 1][j]; //exclude the item
            }
        }
    }
    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            printf("%d ", knapsack_matrix[i][j]);//print table
        }
        printf("\n");
    }
    return knapsack_matrix[row - 1][column - 1];
}

int main() {
    int knapsack_capacity = 5;
    int value[] = {3, 4, 5, 6};
    int weight[] = {2, 3, 4, 5};
    int row = 5;        // Number of items + 1
    int column = 6;     // Knapsack capacity + 1

    int max_value = knapsack(row, column, value, weight, knapsack_capacity);
    printf("The maximum value of knapsack is %d\n", max_value);
return 0;
}
