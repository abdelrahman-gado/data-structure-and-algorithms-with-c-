#include <iostream>
#include <vector>

void selection_sort (std::vector<int> &vec)
{
    for (int i {0}; i < vec.size()-1; i++)
    {
        int smallest_item = vec[i];
        int smallest_index = i;
        
        for (int j {i+1}; j < vec.size(); j++)
        {
            if (vec[j] < smallest_item)
            {
                smallest_item = vec[j];
                smallest_index = j;
            }
        }
        
        int temp = vec[i];
        vec[i] = smallest_item;
        vec[smallest_index] = temp;
//        std::swap(vec[i], vec[smallest_index]);
        
    }
}

void print_list (std::vector<int> &vec)
{
    for (int item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    
    std::vector<int> vec {8, 5, 6, 12, 20, 1, 0, 4};
    selection_sort(vec);
    print_list(vec);
    
    return 0;
}