#include <iostream>
#include <vector>


template <typename T>
class Stack
{
private:
    std::vector<T> data;
    
public:
    Stack()
    {
        
    }
    
    T peek()
    {
        return data.back();
    }
    
    void push(T val)
    {
        data.push_back(val);
    }
    
    T pop()
    {
        T poped = data.back();
        data.pop_back();
        return poped;
    }
    
    bool isEmpty()
    {
        return data.empty();
    }
    
    int getLength()
    {
        return data.size();
    }
    
    void display()
    {
        Stack temp = *this;
        for (int i {0}; i < getLength(); i++)
        {
            std::cout << temp.pop() << std::endl;
        }
    }
    
};



int main() 
{
    
    Stack<std::string> stack;
    stack.push("google");
    stack.push("udemy");
    stack.push("discord");
    
    stack.display();
    
    stack.pop();
    stack.pop();
    
    
    std::cout << "\n";
    stack.display();
    
    std::cout << "size: " << stack.getLength() << std::endl;
    std::cout << "peek: " << stack.peek() << std::endl;
    
    
    return 0;
}