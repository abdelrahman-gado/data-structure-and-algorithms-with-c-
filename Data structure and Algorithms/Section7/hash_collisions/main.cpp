#include <iostream>
#include <map>
#include <string>

int main() 
{
    
    std::map<int, std::string> users {
        {13 , "Kylie"},
        {1 , "Mohammed"},
        {2, "Ahmed"},
        {3 , "Abdo"}
    };
    
    users[5] = "Magdy";
    
    for (std::pair<int, std::string> user : users)
    {
        std::cout << user.first << " " << user.second << std::endl;
    }
    
    return 0;
}