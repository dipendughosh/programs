#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void insert(int arr[], int *n, int value) {
    if (*n == 0) {
        arr[0] = value;
        (*n)++;
    } else {
        arr[*n] = value;
        (*n)++;
        int i = *n - 1;
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(&arr[i], &arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
}

int returnMax(int arr[]) {
    return arr[0];
}

int deleteMax(int arr[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return max;
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[100], n = 0;
    insert(arr, &n, 4);
    insert(arr, &n, 10);
    insert(arr, &n, 8);
    insert(arr, &n, 15);
    insert(arr, &n, 20);

    printf("Max element: %d\n", returnMax(arr));
    printf("Deleting max element: %d\n", deleteMax(arr, &n));
    printf("Max element after deletion: %d\n", returnMax(arr));

    printf("Heap Sort: ");
    heapSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}