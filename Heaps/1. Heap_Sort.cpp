/*
TC = O(N logN)
SC = O(1)
Link: https://practice.geeksforgeeks.org/problems/heap-sort/1

*/

class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        int largest = i;   // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        for (int i = n / 2 - 1; i > -1; i--)
            heapify(arr, n, i);
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {

        buildHeap(arr, n);

        // Heap sort
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};