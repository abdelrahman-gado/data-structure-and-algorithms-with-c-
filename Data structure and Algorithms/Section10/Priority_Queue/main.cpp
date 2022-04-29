#include <iostream>
#include <string>
#include <vector>

struct Element
{
    std::string data;
    int priority;
};

class PriorityQueue
{
private:
    std::vector<Element> queue;
    
public:
    
    PriorityQueue()
    {
    }
    
    void enqueue(std::string val, int pri)
    {
        Element elem {val, pri};
        std::vector<Element>::iterator it;
        for (it = queue.begin(); it != queue.end(); it++)
        {
            if (it->priority > elem.priority)
            {
                queue.insert(it, elem);
                break;
            }
        }
        
        if (it == queue.end())
        {
            queue.push_back(elem);
        }
    }
    
    std::string dequeue()
    {
        if (queue.empty())
        {
            return "Error, the priority queue is empty";
        }
        std::string temp = queue.back().data;
        queue.pop_back();
        return temp;
    }
    
    std::string front()
    {
        if (queue.empty())
        {
            return "Error, the priority queue is empty";
        }
        return queue.back().data;
    }
    
    std::string rear()
    {
        if (queue.empty())
        {
            return "Error, the priority queue is empty";
        }
        return queue.front().data;
    }
    
    void display_priority_queue()
    {
        std::cout << "[ ";
        for (auto it = queue.rbegin(); it != queue.rend(); it++)
        {
            std::cout << it->data << " ";
        }
        std::cout << "]" << std::endl;
    }
};


int main() 
{
    
    PriorityQueue q;
    
    q.enqueue("Sumit", 2);
    q.enqueue("Gourav", 1);
    q.enqueue("Piyush", 1);
    q.enqueue("Sunny", 2);
    q.enqueue("Sheru", 3);
    
    q.display_priority_queue();
    std::cout << q.front() << std::endl;
    std::cout << q.rear() << std::endl;
    
    std::cout << q.dequeue() << std::endl;
    q.enqueue("Sunil", 2); 
    q.display_priority_queue();
    
    return 0;
}