#include <iostream>
#include <vector>  // dynamic array

int main() 
{
    
//    char array[5] = {'a', 'b', 'c', 'd'};
//    
//    std::cout << array[0] << std::endl; // O(1)  --> lookup (access)
//    
//    array[4] = 'e';
//    
//    std::cout << array[4] << std::endl;
//    
//    // delete O(n)
////    for (int i {0}; i < 5; i++)
////    {
////        if (array[i] == 'c')
////        {
////            array[i] = NULL;
////        }
////        
////    }
//    
//    // insert O(n)
//    char array2[6];
//    array2[0] = 'w';
//    
//    for (int i {0}; i < 5; i++)
//    {
//        array2[i+1] = array[i];
//    }
//    
//    for (int i {0}; i < 6; i++)
//    {
//        std::cout << array2[i] << " ";
//    }
//    std::cout << std::endl;

    
    
    std::vector<char> array1 {'a', 'b', 'c', 'd', 'e'};   // 0x123
    
    
    // lookup O(1)
    std::cout << array1[3] << std::endl;     // 0x123 + (3+1)* 4b
    
    // push O(n)
    array1.push_back('f');
    
    // insert O(n)
    array1.insert(array1.begin()+2, 't');
    
    // pop O(1)
    array1.pop_back();
    
    
    // erase (delete) O(n)
    array1.erase(array1.begin()+2);
    
    for (char c : array1)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    
    return 0;
}