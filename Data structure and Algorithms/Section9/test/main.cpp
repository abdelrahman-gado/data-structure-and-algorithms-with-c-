#include <iostream>

#include <stack>
#include <cctype>
#include <string>
#include <vector>

class Solution {
public:
    bool isdigit (std::string &s)
    {
        for (int i {0}; i < s.size(); i++)
        {
            if (!std::isdigit(s[i]))
                return false;
        }
        return true;
    }
    
    
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<std::string> ss;
        for (int i {0}; i < tokens.size(); i++)
        {
            if (ss.empty())
            {
                ss.push(tokens[i]);
            }
            else if (isdigit(tokens[i]))
            {
                ss.push(tokens[i]);
            }
            else
            {
                int result {0};
                int first_op = std::stoi(ss.top());
                ss.pop();
                int second_op = std::stoi(ss.top());
                ss.pop();
                if (tokens[i] == "+")
                    result = first_op + second_op;
                else if (tokens[i] == "-")
                    result = first_op - second_op;
                else if (tokens[i] == "*")
                    result = first_op * second_op;
                else if (tokens[i] == "/")
                    result = second_op / first_op;
                
                ss.push(std::to_string(result));
            }
        }
        
        return std::stoi(ss.top());
    }
};

int main() 
{
    Solution s;
    std::vector<std::string> vec = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << s.evalRPN(vec) << std::endl; 
    
    return 0;
}