#include <stdio.h>
#include <stdlib.h>

int min_index(const int *array, const int size)
{
    int min = array[0];
    int min_index = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            min_index = i;
        }
    }
    return min_index;
}

void reverse(int *array, const int size, int *cost)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
    *cost = *cost + size;
}

int reversort(int *array, int size)
{
    int cost = 0;
    for (int i = 0; i < size; i++)
    {
        int j = min_index(array + i, size - i);
        reverse(array + i, j + 1, &cost);
    }
    return cost;
}

int main()
{
    int num_test_cases;
    scanf("%d", &num_test_cases);
    for (int i = 0; i < num_test_cases; i++)
    {
        int size;
        scanf("%d", &size);
        int *array = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &array[i]);
        }
        printf("Case #%d: %d\n", i+1, reversort(array, size) - 1);
        free(array);
    }
    return 0;
}
