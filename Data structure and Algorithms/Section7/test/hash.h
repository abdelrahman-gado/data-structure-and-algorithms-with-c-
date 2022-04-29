#include <string>

template<typename T> class hash;

template<>
class hash <std::string>
{
public:
    size_t operator() (const string &key)
    {
        size_t hashVal = 0;
        
        for (char ch : key)
            hashVal = 37 * hashVal + ch;
            
        return hashVal;
    }
};