#include <iostream>
#include <list>

template <typename T>
class Stack
{
    
private:
    std::list<T> data;
    
public:
    
    Stack()
    {
        
    }
    
    T peek()
    {
        return data.front();
    }
    
    void push(T val)
    {
        data.push_front(val);
    }
    
    T pop()
    {
        T poped = data.front();
        data.pop_front();
        return poped;
    }
    
    bool isEmpty()
    {
        return data.empty;
    }
    
    int getLength()
    {
        return data.size();
    }
    
    void display()
    {
        Stack<T> temp = *this;
        for (int i {0}; i < data.size(); i++)
        {
            std::cout << temp.pop() << std::endl;
        }
    }
    
};


int main() 
{
    
    Stack<std::string> stack;
    stack.push("google");
    stack.push("udmey");
    stack.push("discord");
    
    stack.display();
    
    stack.pop();
    stack.pop();
    stack.pop();
    
    std::cout << std::endl;
    
    stack.display();
    
    std::cout << "size: " << stack.getLength() << std::endl;
    std::cout << "peek: " << stack.peek() << std::endl;
    
    
    return 0;
}
//[1,2,3,7,8,11,12,9,10,4,5,6]
//[1,2,3,7,8,11,12,9,10,4,5,6]