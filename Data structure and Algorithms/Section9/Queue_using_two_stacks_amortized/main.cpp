#include <iostream>
#include <stack>

class Queue
{
private:
    std::stack<int> s1;
    std::stack<int> s2;
    int front;
    
    

public:
    
    Queue()
    {
        
    }
    
    void push(int x)
    {
        if (s1.empty())
        {
            front = x;
        }
        s1.push(x);
    }
    
    
    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int temp = s2.top();
            s2.pop();
            return temp;
        }
        else
        {
            int temp = s2.top();
            s2.pop();
            return temp;
        }
    }
    
    int peek()
    {
        if (s2.empty())
        {
            return front;
        }
        return s2.top();
    }
    
    bool isEmpty()
    {
        return s1.empty() && s2.empty();
    }
    
};


int main() 
{
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    std::cout << "peek: " << queue.peek() << std::endl;
    std::cout << "Poping..." << std::endl;
    while (!queue.isEmpty())
    {
        std::cout << queue.pop() << std::endl;
    }
    return 0;
}