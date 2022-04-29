#include <iostream>
#include <vector>

std::vector<int> mergeSortedArrays (std::vector<int> arr1, std::vector<int> arr2)
{
    // check input
    if (arr1.size() == 0)
        return arr2;
    
    if (arr2.size() == 0)
        return arr1;
    
    std::vector<int> merged_array;
    int start1 = 0;
    int start2 = 0;
    while (start1 < arr1.size() && start2 < arr2.size())
    {
        if (arr1[start1] < arr2[start2])
        {
            merged_array.push_back(arr1[start1]);
            start1++;
        }
        else
        {
            merged_array.push_back(arr2[start2]);
        }            start2++;
        }

    }
    
    if (start1 < arr1.size())
    {
        for (int i = start1; i < arr1.size(); i++)
        {
            merged_array.push_back(arr1[i]);
        }
    }
    else
    {
        for (int i = start2; i < arr2.size(); i++)
        {
            merged_array.push_back(arr2[i]);
        }
    }
    
    return merged_array;
}


int main() 
{
    std::vector<int> vec = mergeSortedArrays({2, 4, 5, 10}, {3, 10, 12, 15});
    
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    
    return 0;
}