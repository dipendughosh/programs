#include <iostream>

using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to insert a value into the priority queue (max heap)
void insert(int arr[], int& n, int value) {
    // Increase heap size
    n = n + 1;

    // Insert new key at the end
    arr[n - 1] = value;

    // Fix the max heap property if it is violated
    int i = n - 1;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to return the maximum value (root of the max heap)
int return_max(int arr[], int n) {
    return arr[0];
}

// Function to delete and return the maximum value (root of the max heap)
int delete_max(int arr[], int& n) {
    // Check for empty heap
    if (n == 0) {
        return -1; // Indicate empty heap
    }

    int maxValue = arr[0];

    // Move last element to root
    arr[0] = arr[n - 1];
    n = n - 1;

    // Call max heapify on the reduced heap
    heapify(arr, n, 0);

    return maxValue;
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n = 10;
    //int arr[10] = {};// {10, 5, 30, 20, 80};
    int *arr = new int(n);
    //int n = sizeof(arr) / sizeof(arr[0]);
    n=0;
    // Using our custom priority queue functions
    insert(arr, n, 10);
    insert(arr, n, 5);
    insert(arr, n, 30);
    insert(arr, n, 20);
    insert(arr, n, 80);
    insert(arr, n, 90); // Insert a new value  

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Maximum value: " << return_max(arr, n) << endl;

    cout << "Heap sorted array: ";
    heapSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Maximum value deleted: " << delete_max(arr, n) << endl;

    return 0;
}