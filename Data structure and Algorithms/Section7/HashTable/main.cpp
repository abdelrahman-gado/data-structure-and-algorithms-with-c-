#include <iostream>
#include <string>
#include <vector>

class Hashtable
{
private:
    int size;
    std::vector<auto> v;
    
    int _hash(std::string key)
    {
        int hash = 0;
        for (int i {0}; i < key.length(); i++)
        {
            hash = (hash + key[i] * i) % size;
        }
        return hash;
    }
    
    
public:
    Hashtable(int size) : size {size}
    {
        data = new int[size];
    }
    
    void set(std::string key, int value)
    {
       
    }
    
};


int main() 
{
    return 0;
}