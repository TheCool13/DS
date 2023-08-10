#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int recur(int a[], int key, int low, int high) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (key == a[mid])
        return mid;
    if (key < a[mid])
        return recur(a, key, low, mid - 1);
    return recur(a, key, mid + 1, high);
}

int main() {
    int key, *a, i, n, res, repeat;

    do {
        printf("Enter n: ");
        scanf("%d", &n);
        a = (int *)malloc(n * sizeof(int));

        printf("Enter %d numbers:\n", n);
        for (i = 0; i < n; i++)
            scanf("%d", (a + i));

        bubbleSort(a, n);

        printf("Enter the key to be searched: ");
        scanf("%d", &key);
        res = recur(a, key, 0, n - 1);

        if (res == -1)
            printf("Key not found\n");
        else
            printf("%d found at location %d\n", key, res + 1);

        printf("Press 1 to continue: ");
        scanf("%d", &repeat);
    } while (repeat == 1);

    free(a);
    return 0;
}
