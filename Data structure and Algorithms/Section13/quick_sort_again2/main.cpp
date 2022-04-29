#include <iostream>
#include <vector>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    for (int j {low}; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[j], arr[i]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    
    return i+1;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

void print_list(int arr[], int size)
{
    for (int i {0}; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    int arr[] {9, 8, 6, 5, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, size-1);
    print_list(arr, size);
    
    return 0;
}