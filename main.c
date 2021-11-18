#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int midfind(int array[], int low, int high) {
    int mid = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= mid) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}


void quick_sort(int array[], int low, int high) {
    if (low < high) {

        int pi = midfind(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

void printing(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


    int main() {

        int n = 100000;
        int arr1[n];
        srand(0);
        for (int i = 0; i < 100000; i++) {
            arr1[i] = rand();
        }

        clock_t start_t1, end_t1;

        start_t1 = clock();
        quick_sort(arr1, 0, 100000);
        end_t1 = clock();

        printf("The array is sorted using Quick Sort in: %ld seconds", end_t1);


    }
