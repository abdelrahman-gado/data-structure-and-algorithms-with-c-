#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &vec)
{
    for (int i {0}; i < vec.size()-1; i++)
    {
        bool isSorted = true;
        
        for (int j {0}; j < vec.size()-i-1; j++)
        {
            if (vec[j] > vec[j+1])
            {
//                int temp = vec[j];
//                vec[j] = vec[j+1];
//                vec[j+1] = temp;
                std::swap(vec[j], vec[j+1]);
                isSorted = false;
            }
        }
        
        if (isSorted)
            break;
    }
}

void print_list (std::vector<int> &vec)
{
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    std::vector<int> vec {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    bubble_sort(vec);
    print_list(vec);
    
    return 0;
}