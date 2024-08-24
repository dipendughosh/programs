#include <iostream>

class MaxHeap {
private:
    int *heapArray;
    int capacity;
    int heapSize;

public:
    MaxHeap(int cap) {
        capacity = cap;
        heapArray = new int[capacity];
        heapSize = 0;
    }

    ~MaxHeap() {
        delete[] heapArray;
    }

    void insert(int value) {
        if (heapSize == capacity) {
            std::cout << "Heap Overflow\n";
            return;
        }

        heapSize++;
        int i = heapSize - 1;
        heapArray[i] = value;

        while (i != 0 && heapArray[(i - 1) / 2] < heapArray[i]) {
            std::swap(heapArray[i], heapArray[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int returnMax() {
        if (heapSize == 0) {
            std::cout << "Heap is empty\n";
            return -1;
        }

        return heapArray[0];
    }

    int deleteMax() {
        if (heapSize == 0) {
            std::cout << "Heap is empty\n";
            return -1;
        }

        if (heapSize == 1) {
            heapSize--;
            return heapArray[0];
        }

        int root = heapArray[0];
        heapArray[0] = heapArray[heapSize - 1];
        heapSize--;
        maxHeapify(0);

        return root;
    }

    void maxHeapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize && heapArray[left] > heapArray[largest])
            largest = left;

        if (right < heapSize && heapArray[right] > heapArray[largest])
            largest = right;

        if (largest != i) {
            std::swap(heapArray[i], heapArray[largest]);
            maxHeapify(largest);
        }
    }

    void heapSort() {
        for (int i = heapSize / 2 - 1; i >= 0; i--)
            maxHeapify(i);

        for (int i = heapSize - 1; i >= 0; i--) {
            std::swap(heapArray[0], heapArray[i]);
            maxHeapify(0);
        }
    }

    void printHeap() {
        std::cout << "Heap: ";
        for (int i = 0; i < heapSize; i++) {
            std::cout << heapArray[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap(10);

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);
    maxHeap.insert(50);

    std::cout << "Max element in heap: " << maxHeap.returnMax() << std::endl;

    maxHeap.deleteMax();
    std::cout << "Max element deleted from heap\n";

    std::cout << "Max element in heap after deletion: " << maxHeap.returnMax() << std::endl;

    maxHeap.printHeap();

    maxHeap.heapSort();
    std::cout << "Sorted array: ";
    maxHeap.printHeap();

    return 0;
}