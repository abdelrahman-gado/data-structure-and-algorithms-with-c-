#include <iostream>
#include <vector>

std::vector<int> merge (std::vector<int> &left_vec, std::vector<int> &right_vec)
{
    std::vector<int> complete_vec;
    int l_idx = 0;
    int r_idx = 0;
    while (l_idx < left_vec.size() && r_idx < right_vec.size())
    {
        if (left_vec[l_idx] <= right_vec[r_idx])
        {
            complete_vec.push_back(left_vec[l_idx]);
            l_idx++;
        }
        else
        {
            complete_vec.push_back(right_vec[r_idx]);
            r_idx++;
        }
    }
    
    while (l_idx < left_vec.size())
    {
        complete_vec.push_back(left_vec[l_idx]);
        l_idx++;
    }
    
    while (r_idx < right_vec.size())
    {
        complete_vec.push_back(right_vec[r_idx]);
        r_idx++;
    }
    
    return complete_vec;
}


std::vector<int> merge_sort (std::vector<int> &vec)
{
    if (vec.size() <= 1)
        return vec;
    
    int mid = vec.size()/2;
    std::vector<int> left (vec.begin(), vec.begin()+mid);
    std::vector<int> left_vec = merge_sort(left);
    std::vector<int> right (vec.begin()+mid, vec.end());
    std::vector<int> rigth_vec = merge_sort(right);
    
    return merge(left_vec, rigth_vec);
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
    std::vector<int> vec {12, 34, 4, 1, 3, 13, 48, 0};
    vec = merge_sort(vec);
    print_list(vec);
    
    return 0;
}