#include <iostream>
#include <vector>

template <typename T>
void insertion_sort(std::vector<T> &vec)
{
    for (int i {1}; i < vec.size(); i++)
    {
        T num = vec[i];
        int j = i-1;
        while (j >= 0 && vec[j] > num)
        {
            vec[j+1] = vec[j];
            j--;
        }
        
        vec[j+1] = num;
    }
    
}


template <typename T>
void print_list(std::vector<T> &vec)
{
    for (T item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    std::vector<int> vec {433, 23, 21, 5, 65, 4};
    insertion_sort<int>(vec);
    print_list<int>(vec);
    return 0;
}