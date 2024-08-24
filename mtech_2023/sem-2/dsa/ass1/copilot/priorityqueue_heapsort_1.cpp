#include <iostream>
#include <queue> // Include the priority_queue library
#include <unistd.h>

using namespace std;

// Function to insert a value into the max heap
void insert(priority_queue<int>& maxHeap, int value) {
    maxHeap.push(value);
    //cout << "\t" << value;    
}

// Function to return the maximum element from the max heap
int return_max(priority_queue<int>& maxHeap) {
    if (!maxHeap.empty()) {
        return maxHeap.top();
    }
    // Handle the case when the heap is empty
    cerr << "Heap is empty. Cannot return maximum element." << endl;
    return -1; // You can choose an appropriate value here
}

// Function to delete the maximum element from the max heap
void delete_max(priority_queue<int>& maxHeap) {
    if (!maxHeap.empty()) {
        maxHeap.pop();
    } else {
        cerr << "Heap is empty. Cannot delete maximum element." << endl;
    }
}

void heapsort(priority_queue<int>& maxHeap, priority_queue<int>& sortedHeap) {

    while(!maxHeap.empty()) {
        insert(sortedHeap, return_max(maxHeap));
        delete_max(maxHeap);
    }
}

void print_heap(priority_queue<int>& maxHeap) {

    priority_queue<int> temp = maxHeap;
    cout << "Heap size: " << temp.size() << endl;
    cout << "Current Heap:" << endl;
    for (int i = 0; i < temp.size(); i++) {
        cout << "[" << i+1 << "]\t";
    }
    cout << endl;
    while(!temp.empty()) {
        cout << temp.top() << "\t";
        temp.pop();
    }
    cout << endl;
}

int main() {
    // Create a max heap (priority queue)
    priority_queue<int> maxHeap;

    // Insert elements into the max heap
    cout << "Inserting: ";
    insert(maxHeap, 10);
    insert(maxHeap, 20);
    insert(maxHeap, 5);
    insert(maxHeap, 24);
    insert(maxHeap, 1);
    insert(maxHeap, 6);
    insert(maxHeap, 8);
    insert(maxHeap, 90);
    insert(maxHeap, 23);
    insert(maxHeap, 65);
    insert(maxHeap, 76);
    insert(maxHeap, 84);
    insert(maxHeap, 69);
    insert(maxHeap, 53);
    insert(maxHeap, 92);
    insert(maxHeap, 3);
    cout << endl;

    cout << "Current Heap" << endl;
    print_heap(maxHeap);
    // Return and print the maximum element
    //cout << "Maximum element: " << return_max(maxHeap) << endl;

    // Delete the maximum element
    //delete_max(maxHeap);

    // Return and print the new maximum element
    //cout << "New maximum element: " << return_max(maxHeap) << endl;

    priority_queue<int> sortedHeap;
    heapsort(maxHeap, sortedHeap);
    cout << endl << "Sorted Heap" << endl;
    print_heap(sortedHeap);

    return 0;
}