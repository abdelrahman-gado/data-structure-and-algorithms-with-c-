#include <iostream>
#include <vector>

template <typename T>
void selection_sort (std::vector<T> &vec)
{
    for (int i {0}; i < vec.size()-1; i++)
    {
        int small_item_idx {i};
        
        for (int j {i+1}; j < vec.size(); j++)
        {
            if (vec[j] < vec[small_item_idx])
            {
                small_item_idx = j;
            }
        }
        
        std::swap(vec[i], vec[small_item_idx]);
    }
    
}

template <typename T>
void print_list (std::vector<T> &vec)
{
    for (T item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int main() 
{
    
    std::vector<int> vec {1, 2, 446, 6, 0, 3, 9, 2, 3, 90};
    selection_sort<int>(vec);
    print_list<int>(vec);
    
    return 0;
}