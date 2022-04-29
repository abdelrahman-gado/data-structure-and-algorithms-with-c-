#include <iostream>
#include <vector>

void insertion_sort (std::vector<int> &vec)
{
    for (int i {1}; i < vec.size(); i++)
    {
        int curr_item = vec[i];
        int j = i-1;
        while (j >= 0 && vec[j] > curr_item)
        {
            vec[j+1] = vec[j];
            j--;
        }
        
        vec[j+1] = curr_item;
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
    std::vector<int> vec {5, 31, 41, 68, 51, 24};
    insertion_sort(vec);
    print_list(vec);
    
    return 0;
}