#include <iostream>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left_idx = 2*i+1;
    int right_idx = 2*i+2;
    
    if (left_idx < n && arr[left_idx] > arr[i])
        largest = left_idx;
    
    if (right_idx < n && arr[right_idx] > arr[i])
        largest = right_idx;
    
    if (i != largest)
    {
        std::swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void build_heap(int arr[], int n)
{
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heap_sort(int arr[], int n)
{
    build_heap(arr, n);
    for (int i {n-1}; i > 0; i--)
    {
        std::swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

void print_list(int arr[], int n)
{
    for (int i {0}; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}



int main() 
{
    int arr[] {9, 8, 7, 6, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr, size);
    print_list(arr, size);
    
    return 0;
}