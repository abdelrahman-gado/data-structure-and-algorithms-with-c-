#include <iostream>
#include <vector>

void selection_sort(std::vector<int> &list)
{
    for (int i {0}; i < list.size()-1; i++)
    {
        int smallest_val = list[i];
        int smallest_idx = i;
        for (int j {i+1}; j < list.size(); j++)
        {
            if (list[j] < smallest_val)
            {
                smallest_val = list[j];
                smallest_idx = j;
            }
        }
        
        std::swap(list[i], list[smallest_idx]);
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
    selection_sort(list);
    print_list(list);
    
    return 0;
}