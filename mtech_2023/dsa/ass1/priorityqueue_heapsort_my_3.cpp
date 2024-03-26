/*
README :
    The program takes number of elements as input from the user.
    Then it takes each element as input from the user separated by a space.
    Creates the initial Priority Queue.
    A new element can be inserted to the Priority Queue only if it is not full.
    The maximum element can be fetched from the Priority Queue only if it is not empty.
    The maximum element can be deleted from the Priority Queue only if it is not empty.
    The elements of the Priority Queue can be sorted using heap sort if it is not empty.
    The elements of the Priority can be printed after each step.
    Once sorting is done the heap is cleared.

    setPriorityQueueSize() -
        Take the number of elements as input from user.
    getPriorityQueueElements() -
        Take each element as input from the user.
    insertElement(int) -
        Insert a new element into the Priority Queue if it is not full.
    getMax() -
        Fetch the maximum element of the Priority Queue if it is not empty.
    deleteMax() -
        Delete the maximum element of the Priority Queue if it is not empty.
    heapSort() -
        Use heap sort to sort the elements of the Priority Queue in ascending(small to big)
        order if it is not empty. Print the sorted heap. Clear the heap.
    printPriorityQueue() -
        Print the Priority Queue at any stage of the program.
 */

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class PriorityQueue
{
private:
    // Array to store the Heap
    int *heapArray;
    // Maximum size of the array
    int capacity;
    // Size of the heap
    int heapSize;
    // Total number of elements present in the array
    int totalElements;

    // Return parent index
    int getParent(int index)
    {
        return (index - 1) / 2;
    }

    // Return left child index
    int getLeftChild(int index)
    {
        return (2 * index) + 1;
    }

    // Return right child index
    int getRightChild(int index)
    {
        return (2 * index) + 2;
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

    // Swap 2 elements
    void swap(int &first, int &second)
    {
        int temp = first;
        first = second;
        second = temp;
    }

    // Reset the heap
    void resetHeap()
    {
        heapSize = 0;
        totalElements = 0;
    }

    // Function to maxHeapify a subtree rooted at index
    void maxHeapify(int heapArray[], int heapSize, int index)
    {
        // Initialize largest as root
        int largest = index;
        // Left child
        int left = getLeftChild(index);
        // Right child
        int right = getRightChild(index);

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

    // Function to delete and return the maximum value
    int deleteElement()
    {
        // Check for empty heap
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

    // Validate the range of the element to insert in the heap
    bool validateElementRange(int n)
    {
        if (n >= 500 || n <= 0)
        {
            cout << "Error : Invalid input [" << n << "] - Acceptable Priority Queue elements range is (1 to 499)." << endl;
            return false;
        }
        return true;
    }

    // Set the heap size
    void setHeapSize(int n)
    {
        capacity = n;
        createHeap();
    }

    // Create the heap
    void createHeap()
    {
        heapArray = new int[capacity];
    }

public:
    // Constructor of the class
    PriorityQueue()
    {
        // By default the capacity of the array will be 100
        capacity = 100;
        heapSize = 0;
        totalElements = 0;
    }

    // Destructor of the class
    ~PriorityQueue()
    {
        delete[] heapArray;
    }

    // Get the capacity of the array
    int getCapacity()
    {
        return capacity;
    }

    // Set the capacity of the array
    void setCapacity(int cap)
    {
        capacity = cap;
    }

    // Get the heap size
    int getHeapSize()
    {
        return heapSize;
    }

    // Get the total number of elements of the array
    int getTotalElements()
    {
        return totalElements;
    }

    // Function to insert a value into the priority queue (max heap)
    int insertElement(int value)
    {
        // Check if the heap is full or not
        if (isHeapFull())
        {
            cout << "Failed : Priority Queue is full!!! Cannot Insert: [" << value << "]." << endl;
            // Indicate heap is full
            return -1;
        }
        // Validate the range of the element
        if (!validateElementRange(value))
        {
            return -1;
        }
        // Increase heap size
        heapSize = heapSize + 1;
        // Increase total number of elements
        totalElements = heapSize;
        // Insert new element at the end
        heapArray[heapSize - 1] = value;

        // Fix the max heap property if it is violated
        int loopIndex = heapSize - 1;
        while (loopIndex > 0)
        {
            loopIndex = getParent(loopIndex);
            // Call max maxHeapify on the modified heap
            maxHeapify(heapArray, heapSize, loopIndex);
        }

        return 0;
    }

    // Function to return the maximum value
    int getMax()
    {
        // Check if the heap is sorted or not
        if (isHeapEmpty() && !isArrayEmpty())
        {
            cout << "Warning : Priority Queue is sorted." << endl;
            // Indicate empty heap
            return -1;
        }
        // Check if the heap is empty or not
        if (isHeapEmpty())
        {
            cout << "Failed : Priority Queue is empty!!! Cannot fetch max element." << endl;
            // Indicate empty heap
            return -1;
        }
        return heapArray[0];
    }

    // Function to delete and return the maximum value
    int deleteMax()
    {
        int maxValue = deleteElement();
        // Check if the heap is sorted or not
        if (maxValue == -1 && totalElements != 0)
        {
            cout << "Warning : Priority Queue is sorted." << endl;
            // Indicate empty heap
            return -1;
        }
        // Check if the heap is empty or not
        if (maxValue == -1)
        {
            cout << "Failed : Priority Queue is empty!!! Cannot delete max element." << endl;
            // Indicate empty heap
            return -1;
        }
        // Reduce the total number of elements after deletion
        totalElements = totalElements - 1;

        return maxValue;
    }

    // Function to perform heap sort on the priority queue
    void heapSort()
    {
        // Check if heap is sorted or not
        if (isHeapEmpty() && !isArrayEmpty())
        {
            cout << "Warning : Priority Queue is sorted." << endl;
            printHeapSort();
            // Indicate empty heap
            return;
        }
        // Check if the heap is empty or not
        if (isHeapEmpty())
        {
            cout << "Failed : Priority Queue is empty!!! Nothing to sort." << endl;
            // Indicate empty heap
            return;
        }

        // One by one extract an element from heap
        for (int loopIndex = heapSize - 1; loopIndex >= 0; loopIndex--)
        {
            // Move current root to end
            deleteElement();
        }
        printHeapSort();
        cleanUP();
    }

    // Print the priority queue
    void printPriorityQueue()
    {
        // Check if heap is sorted or not
        if (isHeapEmpty() && !isArrayEmpty())
        {
            cout << "Warning : Priority Queue is sorted." << endl;
            printHeapSort();
            return;
        }
        // Check if heap is empty or not
        if (isHeapEmpty())
        {
            cout << "Failed : Priority Queue is empty!!! Nothing to print." << endl;
            // Indicate empty heap
            return;
        }

        // Print priority queue
        cout << "Current Priority Queue : ";
        for (int loopIndex = 0; loopIndex < heapSize; loopIndex++)
        {
            cout << heapArray[loopIndex] << " ";
        }
        cout << endl;
    }

    // Print the sorted heap
    void printHeapSort()
    {
        // Check if the array is empty or not
        if (isArrayEmpty())
        {
            cout << "Failed : Heap is empty!!! Nothing to print." << endl;
            // Indicate empty heap
            return;
        }

        // Print sorted array
        cout << "Sorted Priority Queue or Sorted Heap : ";
        for (int loopIndex = 0; loopIndex < totalElements; loopIndex++)
        {
            cout << heapArray[loopIndex] << " ";
        }
        cout << endl;
    }

    // Perform heap cleanup
    void cleanUP()
    {
        resetHeap();
        cout << "Warning : Priority Queue has been cleaned up." << endl;
    }

    // Take the priority queue size or element size from the user
    void setPriorityQueueSize()
    {
        int n;
        bool inputOk;
        do
        {
            cout << "Please enter the size of the priority queue: ";
            cin >> n;

            if (n >= 100 || n <= 0)
            {
                cout << "Error: Acceptable Priority Queue range is (1 to 99)." << endl;
                inputOk = false;
            }
            else
            {
                inputOk = true;
            }
        } while (!inputOk);

        setHeapSize(n);
    }

    // Take the elements of the priority queue as input from the user
    // The input is taken as string with each element space separated
    // After all elements are entered they are stored intot an integer array
    void getPriorityQueueElements()
    {
        string inputString, eachInput;

        cout << "Enter the PriorityQueue elements seperated by spaces: ";
        getline(cin, inputString); // consume the newline from the previous command

        getline(cin, inputString);
        istringstream iss(inputString);
        while (getline(iss, eachInput, ' '))
        {
            insertElement(stoi(eachInput));
        }
        printPriorityQueue();
    }
};

int main()
{
    PriorityQueue queue;
    int returnValue = -1;
    int element;

    // Set the priority queue size as entered by the user
    queue.setPriorityQueueSize();

    // Take input for elements in a priority queue from the user
    queue.getPriorityQueueElements();

    // Insert a new static element - can be any element including user inputs
    element = 430;
    returnValue = queue.insertElement(element);
    cout << "Priority Queue after trying to insert static element [" << element << "]." << endl;
    queue.printPriorityQueue();

    // Query for element with the highest priority i.e. max value
    returnValue = queue.getMax();
    if (returnValue != -1)
    {
        cout << "Maximum value: [" << returnValue << "]." << endl;
    }
    cout << "Priority Queue after max element query." << endl;
    queue.printPriorityQueue();

    // Insert a new static element - can be any element including user inputs
    element = 58;
    returnValue = queue.insertElement(element);
    cout << "Priority Queue after trying to insert static element [" << element << "]." << endl;
    queue.printPriorityQueue();

    // Delete the element with the highest priority i.e. max value
    returnValue = queue.deleteMax();
    if (returnValue != -1)
    {
        cout << "Maximum value deleted: [" << returnValue << "]." << endl;
    }
    cout << "Priority Queue after max element deletion." << endl;
    queue.printPriorityQueue();

    // Insert a new static element - can be any element including user inputs
    element = 394;
    returnValue = queue.insertElement(element);
    cout << "Priority Queue after trying to insert static element [" << element << "]." << endl;
    queue.printPriorityQueue();

    // Get the priority queue elements sorted in non-decreasing order i.e. ascending order
    queue.heapSort();

    return 0;
}