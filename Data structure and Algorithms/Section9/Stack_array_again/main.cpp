#include <iostream>

// Stack with static array

const int SIZE = 128;
class Stack
{
private:
    int *data;
    int top; // index
    
public:
    Stack()
    {
        data = new int[SIZE];
        top = -1;
    }
    
    int pop()
    {
        if (top == -1 || top >= SIZE-1)
        {
            std::cout << "stack is empty or overflowed" << std::endl;
            return -1;
        }
        
        int temp = data[top];
        top--;
        return temp;
    }
    
    int peek()
    {
        if (top == -1 || top >= SIZE-1)
        {
            std::cout << "stack is empty or overflowed" << std::endl;
            return -1;
        }
        
        return data[top];
    }
    
    void push(int val)
    {
        if (top >= SIZE-1)
        {
            std::cout << "stack is overflowed" << std::endl;
            return;
        }
        
        top++;
        data[top] = val;
    }
    
    int getSize()
    {
        return top+1;
    }
    
    int getCapacity()
    {
        return SIZE;
    }
    
    bool isEmpty()
    {
        return (top == -1);
    }
    
    void display()
    {
        if (isEmpty())
        {
            std::cout << "the stack is empty" <<std::endl;
            return;
        }
        
        int i = top;
        while (i >= 0)
        {
            std::cout << data[i] << " ";
            i--;
        }
        std::cout << std::endl;
    }
    
    ~Stack()
    {
        delete [] data;
    }
    
};


int main() 
{
    
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    
    
    stack.display();
    std::cout << "Size: " << stack.getSize() << std::endl;
    
    stack.pop();
    
    stack.display();
    std::cout << "Size: " << stack.getSize() << std::endl;
    stack.pop();
    stack.pop();
    
    stack.display();
    
    return 0;
}