#include <stdio.h>

// Function to maintain the max heap property
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to insert a value into the max heap
void insert(int arr[], int *n, int value) {
    arr[*n] = value;
    (*n)++;
    buildMaxHeap(arr, *n);
}

// Function to return the maximum value (root of the max heap)
int returnMax(int arr[]) {
    return arr[0];
}

// Function to delete the maximum value (root of the max heap)
void deleteMax(int arr[], int *n) {
    if (*n == 0) {
        printf("Heap is empty.\n");
        return;
    }

    arr[0] = arr[*n - 1];
    (*n)--;
    buildMaxHeap(arr, *n);
}

int main() {
    int arr[100]; // Assuming a maximum of 100 elements
    int n = 0; // Number of elements in the heap

    insert(arr, &n, 10);
    insert(arr, &n, 20);
    insert(arr, &n, 5);
    insert(arr, &n, 24);
    insert(arr, &n, 1);
    insert(arr, &n, 6);
    insert(arr, &n, 8);
    insert(arr, &n, 90);
    insert(arr, &n, 23);
    insert(arr, &n, 65);
    insert(arr, &n, 76);
    insert(arr, &n, 84);
    insert(arr, &n, 69);
    insert(arr, &n, 53);
    insert(arr, &n, 92);
    insert(arr, &n, 3);

    printf("Max value: %d\n", returnMax(arr));

    deleteMax(arr, &n);
    printf("Max value after deletion: %d\n", returnMax(arr));

    return 0;
}