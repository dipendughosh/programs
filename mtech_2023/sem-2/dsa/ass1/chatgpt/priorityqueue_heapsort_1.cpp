#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to heapify a subtree rooted with node i which is
// an index in array[].
void heapify(vector<int>& array, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (left < n && array[left] > array[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && array[right] > array[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(array[i], array[largest]);

        // Recursively heapify the affected sub-tree
        heapify(array, n, largest);
    }
}

// Function to insert a new element into the heap
void insert(priority_queue<int>& pq, int value, vector<int>& array) {
    pq.push(value);
    array.push_back(value);
    heapify(array, array.size(), 0);
}

// Function to return the maximum element from the heap
int return_max(vector<int>& array) {
    if (array.empty())
        return -1; // indicating empty heap
    return array[0];
}

// Function to delete the maximum element from the heap
void delete_max(vector<int>& array) {
    if (array.empty())
        return; // Heap is already empty

    swap(array[0], array.back());
    array.pop_back();
    heapify(array, array.size(), 0);
}

// Function to perform heap sort
void heapSort(vector<int>& array) {
    // Build heap (rearrange array)
    for (int i = array.size() / 2 - 1; i >= 0; i--)
        heapify(array, array.size(), i);

    // One by one extract an element from heap
    for (int i = array.size() - 1; i > 0; i--) {
        // Move current root to end
        swap(array[0], array[i]);

        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

int main() {
    vector<int> array = {12, 11, 13, 5, 6, 7};
    priority_queue<int> pq;

    // Insert elements into the heap
    for (int val : array)
        insert(pq, val, array);

    cout << "Initial array: ";
    for (int val : array)
        cout << val << " ";
    cout << endl;
    
    cout << "Max element in the heap: " << return_max(array) << endl;

    // Delete the maximum element from the heap
    delete_max(array);
    cout << "Max element after deletion: " << return_max(array) << endl;

    // Perform heap sort
    heapSort(array);

    // Print sorted array
    cout << "Sorted array: ";
    for (int val : array)
        cout << val << " ";
    cout << endl;

    return 0;
}