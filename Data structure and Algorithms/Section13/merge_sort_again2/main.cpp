#include <iostream>
#include <vector>

std::vector<int> merge (std::vector<int> left_list, std::vector<int> right_list)
{
    std::vector<int> complete_list;
    int l = 0, r = 0;
    
    while (l < left_list.size() && r < right_list.size())
    {
        if (left_list[l] <= right_list[r])
        {
            complete_list.push_back(left_list[l]);
            l++;
        }
        else
        {
            complete_list.push_back(right_list[r]);
            r++;
        }
    }
    
    while (l < left_list.size())
    {
        complete_list.push_back(left_list[l]);
        l++;
    }
    
    while (r < right_list.size())
    {
        complete_list.push_back(right_list[r]);
        r++;
    }
    
    return complete_list;
}

std::vector<int> merge_sort(std::vector<int> list)
{
    if (list.size() <= 1)
        return list;
    
    int mid = list.size() / 2;
    
    std::vector<int> left_list = merge_sort(std::vector<int> (list.begin(), list.begin()+mid));
    std::vector<int> right_list = merge_sort(std::vector<int> (list.begin()+mid, list.end()));
    return merge(left_list, right_list);
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
    list = merge_sort(list);
    print_list(list);
    
    return 0;
}