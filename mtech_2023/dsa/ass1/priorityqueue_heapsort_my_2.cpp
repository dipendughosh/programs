#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

class MaxHeap
{
private:
    int *heapArray;
    // Maximum size of the array
    int capacity;
    // Size of the heap
    int heapSize;
    // Total number of elements present in the array
    int totalElements;

    // Return parent index
    int parent(int index)
    {
        return (index - 1) / 2;
    }

    // Return left child index
    int leftChild(int index)
    {
        return (2 * index) + 1;
    }

    // Return right child index
    int rightChild(int index)
    {
        return (2 * index) + 2;
    }

    // Function to maxHeapify a subtree rooted at index
    void maxHeapify(int heapArray[], int heapSize, int index)
    {
        // Initialize largest as root
        int largest = index;
        // Left child
        int left = leftChild(index);
        // Right child
        int right = rightChild(index);

        // If left child is larger than root
        if (left < heapSize && heapArray[left] > heapArray[largest])
        {
            largest = left;
        }

        // If right child is larger than largest so far
        if (right < heapSize && heapArray[right] > heapArray[largest])
        {
            largest = right;
        }

        // If largest is not root
        if (largest != index)
        {
            swap(heapArray[index], heapArray[largest]);

            // Recursively maxHeapify the affected sub-tree
            maxHeapify(heapArray, heapSize, largest);
        }
    }

    // Swap 2 elements
    void swap(int &first, int &second)
    {
        int temp = first;
        first = second;
        second = temp;
    }

    // Check if the heap is full or not
    bool isHeapFull()
    {
        if (heapSize == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Check if the heap is empty or not
    bool isHeapEmpty()
    {
        if (heapSize == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Check if the array is empty or not
    bool isArrayEmpty()
    {
        if (totalElements == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    // Constructor to initialize private members
    MaxHeap(int cap)
    {
        capacity = cap;
        heapArray = new int[capacity];
        heapSize = 0;
        totalElements = 0;
    }

    // Destructor of the class
    ~MaxHeap()
    {
        delete[] heapArray;
    }

    // Get the capacity of the array
    int get_capacity()
    {
        return capacity;
    }

    // Set the capacity of the array
    void set_capacity(int cap)
    {
        capacity = cap;
    }

    // Get the heap size
    int get_heapSize()
    {
        return heapSize;
    }

    // Set the heap size
    void set_heapSize(int size)
    {
        heapSize = size;
    }

    // Get the total number of elements of the array
    int get_totalElements()
    {
        return totalElements;
    }

    // Set the total number of elements of the array
    void set_totalElements(int total)
    {
        totalElements = total;
    }

    // Function to insert a value into the priority queue (max heap)
    int insert(int value)
    {
        // Check if the heap is full or not
        if (isHeapFull())
        {
            cout << "Heap is full. Insert failed" << endl;
            // Indicate heap is full
            return -1;
        }

        // Increase heap size
        heapSize = heapSize + 1;
        // Increase total number of elements
        totalElements = heapSize;
        // Insert new key at the end
        heapArray[heapSize - 1] = value;

        // Fix the max heap property if it is violated
        int loopIndex = heapSize - 1;
        while (loopIndex > 0)
        {
            loopIndex = parent(loopIndex);
            // Call max maxHeapify on the modified heap
            maxHeapify(heapArray, heapSize, loopIndex);
        }

        return 0;
    }

    // Function to delete and return the maximum value
    int delete_element()
    {
        // Check if the heap is empty or not
        if (isHeapEmpty())
        {
            // Indicate empty heap
            return -1;
        }

        // Get the root element
        int maxValue = heapArray[0];

        // Move last element to root
        heapArray[0] = heapArray[heapSize - 1];
        heapSize = heapSize - 1;

        // Call max maxHeapify on the reduced heap
        maxHeapify(heapArray, heapSize, 0);

        // Insert the deleted element to the end of heap
        heapArray[heapSize] = maxValue;

        return maxValue;
    }

    // Function to return the maximum value
    int return_max()
    {
        // Check if the heap is sorted or not
        if (isHeapEmpty() && !isArrayEmpty())
        {
            cout << "Heap is sorted" << endl;
            // Indicate empty heap
            return -1;
        }
        // Check if the heap is empty or not
        if (isHeapEmpty())
        {
            cout << "Heap is empty. Max element fetch failed" << endl;
            // Indicate empty heap
            return -1;
        }

        return heapArray[0];
    }

    // Function to delete and return the maximum value
    int delete_max()
    {
        int maxValue = delete_element();
        // Check if the heap is sorted or not
        if (maxValue == -1 && totalElements != 0)
        {
            cout << "Heap is sorted" << endl;
            // Indicate empty heap
            return -1;
        }
        // Check if the heap is empty or not
        if (maxValue == -1)
        {
            cout << "Heap is empty. Delete failed" << endl;
            // Indicate empty heap
            return -1;
        }
        // Reduce the total number of elements after deletion
        totalElements = totalElements - 1;

        return maxValue;
    }

    // Function to perform heap sort
    int heapSort()
    {
        // Check if heap is sorted or not
        if (isHeapEmpty() && !isArrayEmpty())
        {
            cout << "Heap is sorted" << endl;
            // Indicate empty heap
            return -1;
        }
        // Check if the heap is empty or not
        if (isHeapEmpty())
        {
            cout << "Heap is empty. HeapSort failed" << endl;
            // Indicate empty heap
            return -1;
        }

        // One by one extract an element from heap
        for (int loopIndex = heapSize - 1; loopIndex >= 0; loopIndex--)
        {
            // Move current root to end
            delete_element();
        }

        return 0;
    }

    // Print the current heap
    void printHeap()
    {
        // Check if heap is sorted or not
        if (isHeapEmpty() && !isArrayEmpty())
        {
            cout << "Heap is sorted" << endl;
            printSortedHeap();
            return;
        }
        // Check if heap is empty or not
        if (isHeapEmpty())
        {
            cout << "Heap is empty." << endl;
            // Indicate empty heap
            return;
        }
        // Print elements of the heap
        cout << "Current Heap : ";
        for (int loopIndex = 0; loopIndex < heapSize; loopIndex++)
        {
            cout << heapArray[loopIndex] << " ";
        }
        cout << endl;
    }

    // Print the sorted heap
    void printSortedHeap()
    {
        // Check if the array is empty or not
        if (isArrayEmpty())
        {
            // Indicate empty heap
            return;
        }

        // Print sorted array
        cout << "Sorted Array : ";
        for (int loopIndex = 0; loopIndex < totalElements; loopIndex++)
        {
            cout << heapArray[loopIndex] << " ";
        }

        cout << endl;
    }

    // Reset the heap
    void reset()
    {
        heapSize = 0;
        totalElements = 0;
        cout << "Heap reset successful" << endl;
    }
};

int main()
{
    int arraySize = INT_MAX;
    MaxHeap heap(arraySize);
    int choice;
    int insertChoice;
    string filePath;
    string element;
    int int_element;
    int max;
    int output;

    // Infinite loop for menu driven
    while (true)
    {
        // Menu items
        cout << "\t\tMenu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete Max" << endl;
        cout << "3. Get Max" << endl;
        cout << "4. Heap Sort" << endl;
        cout << "5. Print Heap" << endl;
        cout << "6. Reset Heap" << endl;
        cout << "7. Exit!!!" << endl;
        cin >> choice;

        // Switch depending on the choice
        switch (choice)
        {
        case 1:
            // Sub-menu for insert
            cout << "\t\tInsert options" << endl;
            cout << "1. Insert an element" << endl;
            cout << "2. Insert from a file" << endl;
            cin >> insertChoice;

            // Switch depending on the choice
            switch (insertChoice)
            {
            // Insert from console
            case 1:
                cout << "Insert elements(any other key to stop) : " << endl;
                while (cin >> element)
                {
                    try
                    {
                        int_element = stoi(element);
                        if (heap.insert(int_element) == -1)
                        {
                            break;
                        }
                    }
                    catch (exception e)
                    {
                        break;
                    }
                }

                break;
            // Insert from a file
            case 2:
                cout << "Input file should contain each element in each line." << endl
                     << "Please do not provide and other character other than integers." << endl
                     << "No special handling is implemented";
                cout << "Enter the full path of the input file : ";
                cin >> filePath;
                fstream myfile(filePath, ios_base::in);
                while (myfile >> int_element)
                {
                    if (heap.insert(int_element) == -1)
                    {
                        break;
                    }
                }
                myfile.close();
                break;
            }
            break;
        // Delete the maximum element
        case 2:
            max = heap.delete_max();
            if (max != -1)
            {
                cout << "Maximum value deleted: " << max << endl;
            }
            break;
        // Display the maximum element
        case 3:
            max = heap.return_max();
            if (max != -1)
            {
                cout << "Maximum value: " << max << endl;
            }
            break;
        // Sort te heap using heap sort
        case 4:
            heap.heapSort();
            heap.printSortedHeap();
            break;
        // Print the current heap
        case 5:
            heap.printHeap();
            break;
        // Reset the heap
        case 6:
            heap.reset();
            break;
        // Exit from the loop
        case 7:
            exit(0);
            break;
        }
    }

    return 0;
}