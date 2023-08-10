#include <stdio.h>

// Function to swap elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort function
void bubbleSort(int array[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}

// Main Function
int main() {
    int Arr[] = {89, 32, 20, 113, -15};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    bubbleSort(Arr, size);
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++)
        printf("%d ", Arr[i]);
    printf("\n");
    return 0;
}
