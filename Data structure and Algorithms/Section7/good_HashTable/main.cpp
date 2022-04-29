#include <iostream>
#include <string>

// This implemention of HashTable is about open addressing

class HashNode
{
public:
    int key;
    int value;

    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class HashTable
{
private:
    HashNode **arr;
    int size_arr;
    
    int hash_function(int key)
    {
        return key % size_arr;
    }
    
public:
    
    HashTable(int size) : size_arr {size}
    {
        arr = new HashNode*[size];
        for (int i {0}; i < size; i++)
        {
            arr[i] = NULL;
        }
    }
    
    void set (int key, int value)
    {
        int hash = hash_function(key);
        while (arr[hash] != NULL && arr[hash]->key != key)
        {
            hash = hash_function(hash + 1);
        }
        
        if (arr[hash] != NULL)
        {
            delete arr[hash];
        }
        
        arr[hash] = new HashNode(key, value);
    }
    
    int get (int key)
    {
        int hash = hash_function(key);
        
        while (arr[hash] != NULL && arr[hash]->key != key)
        {
            hash = hash_function(hash+1);
        }
        
        if (arr[hash] == NULL)
        {
            std::cout << "Not Found this key" << std::endl;
            return -1;
        }
        
        return arr[hash]->value;
    }
    
    void removeValue(int key)
    {
        int hash = hash_function(key);
        if (arr[hash] == NULL)
        {
            std::cout << "No element found" << std::endl;
            return;
        }
        
        while(arr[hash] != NULL)
        {
            if (arr[hash]->key == key)
            {
                break;
            }
            hash = hash_function(hash + 1);
        }
        
        delete arr[hash];
    }
    
    void display()
    {
        for (int i = 0; i < size_arr; i++)
        {
            if (arr[i] != NULL && arr[i]->key != -1)
            {
                std::cout << arr[i]->key << "-----" << arr[i]->value << std::endl;
            }
        }
    }
    
    
};



int main() 
{
    
    HashTable h {3};
    h.set(1, 1);
    h.set(2, 2);
    h.set(2, 3);
    h.set(2, 8);
    h.set(12, 21);
    
    h.display();
    
    std::cout << h.get(2) <<  std::endl;
    
    return 0;
}