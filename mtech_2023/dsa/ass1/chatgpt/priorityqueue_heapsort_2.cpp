#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper function to heapify a subtree rooted at given index
    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    // Function to insert a value into the heap
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        // while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        //     swap(heap[index], heap[(index - 1) / 2]);
        //     index = (index - 1) / 2;
        // }
        while (index > 0) {
            index = (index - 1) / 2;
            heapify(index);
        }
    }

    // Function to return the maximum value in the heap
    int returnMax() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return -1; // or throw an exception
        }
        return heap[0];
    }

    // Function to delete the maximum value from the heap
    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    // Function to perform heap sort
    void heapSort() {
        vector<int> sorted;
        while (!heap.empty()) {
            sorted.push_back(returnMax());
            deleteMax();
        }
        cout << "Sorted array: ";
        for (int num : sorted)
            cout << num << " ";
        cout << endl;
    }

    void printHeap() {
        for (int num : heap)
            cout << num << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    int arr[] = {5, 3, 8, 2, 10, 7};

    cout << "Inserting elements into the heap...\n";
    for (int num : arr)
        heap.insert(num);

    cout << "Initial array: ";
    heap.printHeap();

    cout << "Maximum element in the heap: " << heap.returnMax() << endl;

    cout << "Deleting maximum element from the heap...\n";
    heap.deleteMax();
    cout << "Maximum element in the heap after deletion: " << heap.returnMax() << endl;

    cout << "Performing heap sort...\n";
    heap.heapSort();

    return 0;
}