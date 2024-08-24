#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

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
        int n = heap.size();
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
    // Insert a value into the max heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Return the maximum element from the max heap
    int return_max() {
        if (!heap.empty()) {
            return heap[0];
        }
        cerr << "Heap is empty. Cannot return maximum element." << endl;
        return -1; // You can choose an appropriate value here
    }

    // Delete the maximum element from the max heap
    void delete_max() {
        if (!heap.empty()) {
            swap(heap[0], heap.back());
            heap.pop_back();
            heapifyDown(0);
        } else {
            cerr << "Heap is empty. Cannot delete maximum element." << endl;
        }
    }

    void print_heap() {

        vector<int> temp = this->heap;
        cout << "Heap size: " << temp.size() << endl;
        cout << "Current Heap:" << endl;
        for (int i = 0; i < temp.size(); i++) {
            cout << "[" << i+1 << "]\t";
        }
        cout << endl;
        int i = 0;
        while(!temp.empty()) {
            cout << temp[i] << "\t";
            temp.pop_back();
            i++;
        }
        cout << endl;
    }

    void heapsort(MaxHeap& sortedHeap) {

        while(!this->heap.empty()) {
            sortedHeap.heap.push_back(return_max());
            delete_max();
        }
    }
};

int main() {
    MaxHeap maxHeap;

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
    //cout << "Maximum element: " << maxHeap.return_max() << endl;

    maxHeap.print_heap();
    // Delete the maximum element
    //maxHeap.delete_max();

    MaxHeap sortedHeap;
    // Return and print the new maximum element
    //cout << "New maximum element: " << maxHeap.return_max() << endl;

    maxHeap.heapsort(sortedHeap);
    sortedHeap.print_heap();

    return 0;
}