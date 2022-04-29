#include <iostream>
#include <vector>

template <typename T>
void bubble_sort(std::vector<T> &vec)
{
    for (int i {0}; i < vec.size()-1; i++)
    {
        bool isSorted = true;
        for (int j {0}; j < vec.size()-i-1; j++)
        {
            if (vec[j] > vec[j+1])
            {
                T temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
                isSorted = false;
            }
        }
        
        if (isSorted)
            break;
    }
    
}

template <typename T>
void print_vec (std::vector<T> &vec)
{
    for (T item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int main() 
{
    std::vector<int> vec {6, 5, 3, 1, 8, 7, 2, 4};
    bubble_sort<int>(vec);
    print_vec<int>(vec);
    
    return 0;
}