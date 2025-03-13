#include <stdio.h>
int main()
{
    int arr[2][8] = {
        {1, 3, 0, 5, 8, 5, 12, 2},
        {2, 4, 6, 7, 9, 9, 14, 12}};
    int i, j;
    for (i = 0; i < 8 - 1; i++)
    {
        for (j = 0; j < 8 - i - 1; j++)
        {
            if (arr[1][j] > arr[1][j + 1])
            {
                int temp = arr[0][j];
                temp = arr[1][j];
                arr[0][j] = arr[0][j + 1];
                arr[1][j] = arr[1][j + 1];
                arr[0][j + 1] = temp;
                arr[1][j + 1] = temp;
            }
        }
    }
    printf("Selected Activity:\n");
    i = 0;
    printf("A 1: Start = %d, End = %d\n", arr[0][i], arr[1][i]);
    for (j = 1; j < 8; j++)
    {
  if (arr[0][j] >= arr[1][i])
        {
            printf("A %d: Start = %d, End = %d\n", j + 1, arr[0][j], arr[1][j]);
            i = j;
        }
    }
    return 0;
}
