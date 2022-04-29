#include <iostream>

#include <unordered_set>
#include <cmath>

class Solution {
public:
    bool isHappy(int n) 
    {
        std::unordered_set<int> set1;
        std::string num = std::to_string(n);
        
        while(true)
        {
            if (set1.find(n) != set1.end())
            {
                return false;
            }
            else
            {
                set1.insert(n);
            }
            
            int x = 0;
            for (int i {0}; i < num.size(); i++)
            {
                x += std::pow(num[i]-'0', 2);
            }
            n = x;
            num = std::to_string(x);
            
            if(x == 1){
                return true;
            }
            
           
        }
        
        return false;
    }
};

int main() 
{
    Solution s;
    std::cout << s.isHappy(15) << std::endl;

}