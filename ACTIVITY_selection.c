#include<stdio.h>
int main() {
    int arr[3][3];
    for(int j = 0; j < 8; j++) {
        printf("Enter the %d activity: ", j + 1);
        scanf("%d", &arr[0][j]);
        printf("Enter the start time of %d activity: ", j + 1);
        scanf("%d", &arr[1][j]);
        printf("Enter the finish time of %d activity: ", j + 1);
        scanf("%d", &arr[2][j]);
    }
        for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2- i; j++) {
            if (arr[2][j] > arr[2][j + 1]) {
                for (int k = 0; k < 3; k++) {
                    int temp = arr[k][j];
                    arr[k][j] = arr[k][j + 1];
                    arr[k][j + 1] = temp;
                }
            }
        }
    }
    printf("The elements of the array are:\n");
    for(int j=0;j<8;j++){
printf("A%d\t",j+1);
    }
    printf("\n");
    for(int i = 1; i < 3; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}