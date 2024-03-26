#include <iostream>

class MaxHeap {
private:
    int capacity;
    
    // Helper function to swap two elements in the heap
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Helper function to heapify the subtree rooted at index i
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize && heapArray[left] > heapArray[largest])
            largest = left;

        if (right < heapSize && heapArray[right] > heapArray[largest])
            largest = right;

        if (largest != i) {
            swap(heapArray[i], heapArray[largest]);
            heapify(largest);
        }
    }

public:
    int *heapArray;
    int heapSize;

    // Constructor
    MaxHeap(int cap) {
        capacity = cap;
        heapArray = new int[capacity];
        heapSize = 0;
    }

    // Destructor
    ~MaxHeap() {
        delete[] heapArray;
    }

    // Function to insert a new element into the heap
    void insert(int value) {
        if (heapSize == capacity) {
            std::cout << "Heap overflow\n";
            return;
        }

        // Insert the new element at the end
        int i = heapSize;
        heapArray[i] = value;
        heapSize++;

        // Restore heap property
        while (i != 0 && heapArray[(i - 1) / 2] < heapArray[i]) {
            swap(heapArray[i], heapArray[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Function to return the maximum element in the heap
    int returnMax() {
        if (heapSize == 0) {
            std::cout << "Heap is empty\n";
            return -1; // Assuming -1 as invalid value
        }
        return heapArray[0];
    }

    // Function to delete the maximum element from the heap
    void deleteMax() {
        if (heapSize == 0) {
            std::cout << "Heap is empty\n";
            return;
        }

        // Replace the root with the last element
        heapArray[0] = heapArray[heapSize - 1];
        heapSize--;

        // Heapify the root
        heapify(0);
    }

    // Function to perform heap sort
    void heapSort() {
        for (int i = heapSize / 2 - 1; i >= 0; i--)
            heapify(i);

        for (int i = heapSize - 1; i > 0; i--) {
            swap(heapArray[0], heapArray[i]);
            heapify(0);
        }
    }
};

int main() {
    MaxHeap pq(10); // Create a max heap with capacity 10

    pq.insert(10);
    pq.insert(20);
    pq.insert(15);
    pq.insert(30);
    pq.insert(25);

    std::cout << "Max element: " << pq.returnMax() << std::endl;

    pq.deleteMax();
    std::cout << "Max element after deletion: " << pq.returnMax() << std::endl;

    pq.heapSort();

    std::cout << "Sorted elements: ";
    for (int i = 0; i < pq.heapSize; i++) {
        std::cout << pq.heapArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}