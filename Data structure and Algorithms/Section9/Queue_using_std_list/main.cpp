#include <iostream>
#include <list>


class Queue
{
private:
    std::list<std::string> data;
    
public:
    
    Queue()
    {
        
    }
    
    std::string peek()
    {
        return data.front();
    }
    
    void enqueue(std::string val)
    {
        data.push_back(val);
    }
    
    std::string dequeue()
    {
        std::string temp = data.front();
        data.pop_front();
        return temp;
    }
    
    std::string getLast()
    {
        return data.back();
    }
    
    
    void display()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        
        std::list<std::string> temp = data;
        while (!temp.empty())
        {
            std::cout << temp.front() << " ";
            temp.pop_front();
        }
        std::cout << "\n";
        
    }
    
    bool isEmpty()
    {
        return (data.size() == 0);
    }
    
    int getLength()
    {
        return data.size();
    }
    
};


int main() 
{
    Queue queue;
    queue.enqueue("Joy");
    queue.enqueue("Matt");
    queue.enqueue("pavel");
    queue.enqueue("Samir");
    
    queue.display();
    std::cout << "size: " << queue.getLength() << std::endl;
    std::cout << "peek: " << queue.peek() << std::endl;
    std::cout << "last: " << queue.getLast() << std::endl;
    
    std::cout << "\n";
    
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    
    queue.display();
    std::cout << "size: " << queue.getLength() << std::endl;
    //std::cout << "peek: " << queue.peek() << std::endl;
    //std::cout << "last: " << queue.getLast() << std::endl;
    
    return 0;
}