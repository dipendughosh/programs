#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    // Helper function to maintain the max heap property
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Helper function to restore the max heap property after deletion
    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < n && heap[leftChild] > heap[largest])
                largest = leftChild;
            if (rightChild < n && heap[rightChild] > heap[largest])
                largest = rightChild;

            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Insert a value into the max heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Return the maximum value (root of the max heap)
    int returnMax() {
        if (!heap.empty())
            return heap[0];
        else
            throw std::runtime_error("Heap is empty.");
    }

    // Delete the maximum value (root of the max heap)
    void deleteMax() {
        if (!heap.empty()) {
            std::swap(heap[0], heap.back());
            heap.pop_back();
            heapifyDown(0);
        } else {
            throw std::runtime_error("Heap is empty.");
        }
    }
};

int main() {
    MaxHeap maxHeap;
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

    std::cout << "Max value: " << maxHeap.returnMax() << std::endl;

    maxHeap.deleteMax();
    std::cout << "Max value after deletion: " << maxHeap.returnMax() << std::endl;

    return 0;
}