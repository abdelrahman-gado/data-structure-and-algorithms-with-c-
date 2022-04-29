#include <iostream>
#include <set>
#include <vector>

int first_recurring_number1(std::vector<int> nums)
{
    // Plus the bouns
    int index_j = -1;
    int n = -1;
    for (int i {0}; i < nums.size(); i++)
    {
        for (int j {i+1}; j < nums.size(); j++)
        {
            if (nums[i] == nums[j] && index_j == -1)
            {
                index_j = j;
                n = nums[i];
            }
            
            if (nums[i] == nums[j] && index_j > j)
            {
                index_j = j;
                n = nums[i];
            }
            
        }
    }
    return n;
}

int first_recurring_number2(std::vector<int> nums)
{
    std::set<int> numbers;
    for (int i {0}; i < nums.size(); i++)
    {
        if (numbers.find(nums[i]) != numbers.end())
        {
            return nums[i];
        }
        numbers.insert(nums[i]);
    }
    
    return -1;
}

int main() 
{
    std::cout << first_recurring_number1({2, 3, 4, 2, 5, 2, 1, 2}) << std::endl;
    
    return 0;
}