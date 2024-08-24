#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    int heapSize;

    // Helper function to maintain the max heap property
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Helper function to heapify down
    void heapifyDown(int index) {
        int n = heapSize;
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < n && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < n && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap(int capacity) {
        heap.resize(capacity);
        heapSize = 0;
    }

    // Insert a value into the max heap
    void insert(int value) {
        if (heapSize == heap.size()) {
            cerr << "Heap is full. Cannot insert." << endl;
            return;
        }
        heap[heapSize] = value;
        heapifyUp(heapSize);
        heapSize++;
    }

    // Return the maximum element from the max heap
    int return_max() {
        if (heapSize > 0) {
            return heap[0];
        }
        cerr << "Heap is empty. Cannot return maximum element." << endl;
        return -1; // You can choose an appropriate value here
    }

    // Delete the maximum element from the max heap
    void delete_max() {
        if (heapSize > 0) {
            swap(heap[0], heap[heapSize - 1]);
            heapSize--;
            heapifyDown(0);
        } else {
            cerr << "Heap is empty. Cannot delete maximum element." << endl;
        }
    }
};

int main() {
    MaxHeap maxHeap(10); // Specify the capacity of the heap

    // Insert elements into the max heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(24);
    maxHeap.insert(1);
    maxHeap.insert(6);
    maxHeap.insert(8);
    maxHeap.insert(90);
    maxHeap.insert(23);
    maxHeap.insert(65);
    maxHeap.insert(76);
    maxHeap.insert(84);
    maxHeap.insert(69);
    maxHeap.insert(53);
    maxHeap.insert(92);
    maxHeap.insert(3);

    // Return and print the maximum element
    cout << "Maximum element: " << maxHeap.return_max() << endl;

    // Delete the maximum element
    maxHeap.delete_max();

    // Return and print the new maximum element
    cout << "New maximum element: " << maxHeap.return_max() << endl;

    return 0;
}