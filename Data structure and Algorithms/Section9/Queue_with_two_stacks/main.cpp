#include <iostream>
#include <stack>

class Queue
{
private:
    std::stack<int> s1;
    std::stack<int> s2;
    
    
public:
    
    Queue()
    {
        
    }
    
    void push(int x)
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        else
        {
            s1.push(x);
        }
    }
    
    
    int pop()
    {
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek()
    {
        return s1.top();
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