#include <iostream>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j {low}; j <= high-1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i+1], arr[high]);
    return (i+1);
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

void print_arr (int arr[], int n)
{
    for (int i {0}; i < n ; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main() 
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n-1);
    print_arr(arr, n);
    return 0;
}