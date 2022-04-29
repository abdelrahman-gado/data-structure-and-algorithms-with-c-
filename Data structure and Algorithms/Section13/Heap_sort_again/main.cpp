#include <iostream>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
        
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
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
    for (int i = n-1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main() 
{
    int arr[] = {10, 9, 9, 99, 8, 7, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr, n);
    for (int i {0}; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}