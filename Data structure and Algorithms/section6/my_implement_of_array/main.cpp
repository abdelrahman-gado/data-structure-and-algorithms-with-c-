#include <iostream>
#include <vector>

class MyArray
{
private:
    
    int size;
    int capacity;
    int *arr;
    
public:
    
    MyArray(std::vector<int> vec)
    {
        size = vec.size();
        capacity = vec.size();
        arr = new int[vec.size()];
        for (int i {0}; i < vec.size(); i++)
        {
            arr[i] = vec[i];
        }
    }
    
    MyArray(int length)
    {
        arr = new int[length];
        size = capacity = length;
    }
    
    // O(1)
    int get (int index)
    {
        return arr[index];
    }
    
    // O(n)
    void push(int value)
    {
        if (capacity == size)
        {
            int *temp = new int[capacity*2];
            for (int i {0}; i < size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity = capacity * 2;
        }
        arr[size] = value;
        size++;
        
        
    }
    
    // O(1)
    int pop()
    {
        int item = arr[size];
        size--;
        return item;
    }
    
    // O(n)
    int erase (int index)
    {
        int deleted_item = arr[index];
        for (int i = index; i < size-1; i++)
        {
            arr[i] = arr[i+1];
        }
        size--;
        
        return deleted_item;
    }
    
    // O(n)
    void insert(int value, int index)
    {
        if (size+1 >= capacity)
        {
            push(value);
            for (int i {size}; i > index; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[index] = value; 
        }
        else
        {
            // try not to repeat yourself
            for (int i {size}; i > index; i--)
            {
                arr[i] = arr[i-1];
            }
            size++;
            arr[index] = value; 
            
        }
        
    }
    
    
    int getSize()
    {
        return size;
    }
    
    int getCapacity()
    {
        return capacity;
    }
    
    void print()
    {
        for (int i {0}; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    
    ~MyArray()
    {
        delete[] arr;
    }
    
};



int main() 
{
    
    MyArray a { {11, 12, 22} };
    a.print();
    a.push(120);
    a.print();
    a.insert(11111, 1);
    a.print();
    std::cout << a.getSize() << std::endl;
    std::cout << a.getCapacity() << std::endl;
    a.pop();
    a.print();
    
    return 0;
}