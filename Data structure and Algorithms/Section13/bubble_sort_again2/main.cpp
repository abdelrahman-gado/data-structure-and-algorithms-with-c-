#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &list)
{
    for (int i {0}; i < list.size()-1; i++)
    {
        bool swapped = false;
        for (int j {0}; j < list.size()-1-i; j++)
        {
            if (list[j] > list[j+1])
            {
                std::swap(list[j], list[j+1]);
                swapped = true;
            }
        }
        
        if (!swapped)
            break;
        
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
    bubble_sort(list);
    print_list(list);
    
    return 0;
}