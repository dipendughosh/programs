#include <iostream>

class MaxHeap {
private:
    

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return (2 * index) + 1;
    }

    int rightChild(int index) {
        return (2 * index) + 2;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapify(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heapSize && heapArray[left] > heapArray[largest]) {
            largest = left;
        }

        if (right < heapSize && heapArray[right] > heapArray[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heapArray[index], heapArray[largest]);
            heapify(largest);
        }
    }

public:
    int *heapArray;
    int capacity;
    int heapSize;
    MaxHeap(int capacity) {
        this->capacity = capacity;
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

        int currentIndex = heapSize;
        heapArray[currentIndex] = value;
        heapSize++;

        while (currentIndex != 0 && heapArray[parent(currentIndex)] < heapArray[currentIndex]) {
            swap(heapArray[currentIndex], heapArray[parent(currentIndex)]);
            currentIndex = parent(currentIndex);
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

        int root = heapArray[0];
        heapArray[0] = heapArray[heapSize - 1];
        heapSize--;
        heapify(0);

        return root;
    }

    void heapSort() {
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            heapify(i);
        }

        for (int i = heapSize - 1; i >= 0; i--) {
            swap(heapArray[0], heapArray[i]);
            heapify(0);
        }
    }

    void printHeap() {
        for (int i = 0; i < heapSize; i++ ) {
            std::cout << heapArray[i] << "\t";
        }
        std::cout << "\n";
    }
};

int main() {
    MaxHeap maxHeap(10);
    maxHeap.insert(4);
    maxHeap.insert(10);
    maxHeap.insert(8);
    maxHeap.insert(15);
    maxHeap.insert(20);

    maxHeap.printHeap();

    std::cout << "Max element: " << maxHeap.returnMax() << std::endl;
    std::cout << "Deleting max element: " << maxHeap.deleteMax() << std::endl;
    std::cout << "Max element after deletion: " << maxHeap.returnMax() << std::endl;

    std::cout << "Heap Sort: ";
    maxHeap.heapSort();
    maxHeap.printHeap();
    for (int i = 0; i < maxHeap.heapSize; i++) {
        std::cout << maxHeap.deleteMax() << " ";
    }
    std::cout << std::endl;

    return 0;
}