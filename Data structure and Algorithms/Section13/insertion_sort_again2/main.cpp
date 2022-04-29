#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> &list)
{
    for (int i {1}; i < list.size(); i++)
    {
        int num = list[i];
        int j = i-1;
        while (j >= 0 && num < list[j])
        {
            list[j+1] = list[j];
            j--;
        }
        
        list[j+1] = num; 
    }
}

void print_list(std::vector<int> &list)
{
    for (int item : list)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    std::vector<int> list {9, 9, 8, 7, 6, 5, 3, 1};
    insertion_sort(list);
    print_list(list);
    
    return 0;
}