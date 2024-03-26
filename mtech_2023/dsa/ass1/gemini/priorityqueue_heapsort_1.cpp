#include <iostream>
#include <queue>

using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
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
void insert(vector<int>& arr, int value) {
   arr.push_back(value);
   int i = arr.size() - 1;

   // Fix the min heap property if it is violated
//    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
//        swap(arr[i], arr[(i - 1) / 2]);
//        i = (i - 1) / 2;
//    }
    while (i > 0) {
        i = (i - 1) / 2;
        heapify(arr, arr.size(), i);
    }
}

// Function to return the maximum value (root of the max heap)
int return_max(vector<int>& arr) {
   return arr[0];
}

// Function to delete and return the maximum value (root of the max heap)
int delete_max(vector<int>& arr) {
   int maxValue = arr[0];
   arr[0] = arr.back();
   arr.pop_back();
   heapify(arr, arr.size(), 0);
   return maxValue;
}

// Function to perform heap sort
void heapSort(vector<int>& arr) {
   // Build heap (rearrange array)
   for (int i = arr.size() / 2 - 1; i >= 0; i--) {
       heapify(arr, arr.size(), i);
   }

   // One by one extract an element from heap
   for (int i = arr.size() - 1; i >= 0; i--) {
       // Move current root to end
       swap(arr[0], arr[i]);

       // Call max heapify on the reduced heap
       heapify(arr, i, 0);
   }
}

int main() {
   vector<int> arr;// = {10, 5, 30, 20, 80};

   insert(arr, 10);
   insert(arr, 5);
   insert(arr, 30);
   insert(arr, 20);
   insert(arr, 80);
   insert(arr, 90); // Insert a new value

   cout << "Maximum value: " << return_max(arr) << endl;
   for (int value : arr) {
       cout << value << " ";
   }
   cout << endl;
   cout << "Heap sorted array: ";
   heapSort(arr);
   for (int value : arr) {
       cout << value << " ";
   }
   cout << endl;

   cout << "Maximum value deleted: " << delete_max(arr) << endl;

   return 0;
}