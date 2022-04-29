#include <iostream>
#include <vector>

void mergeArray (int arr[], int low, int mid, int high)
{
    int size1 = mid - low + 1;
    int size2 = high - mid;
    
    int leftArr[size1], rightArr[size2];
    
    for (int i = 0; i < size1; i++)
    {
        leftArr[i] = arr[low + i];
    }
    
    for (int i = 0; i < size2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    
    int i = 0; // left array
    int j = 0; // right array
    int k = low; // original array
    
    while (i < size1 && j < size2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < size1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < size2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
}



void merge_sort (int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + (high-1))/2;
        
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        
        mergeArray(arr, low, mid, high);
        
    }
}


void print_vec (int arr[], int n)
{
    for (int i {0}; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, n);
    
    print_vec(arr, n);
    
    return 0;
}