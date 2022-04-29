#include <iostream>
#include <vector>

template <typename T>
struct Element
{
    T data;
    int priority;
};


template <typename T>
class PriorityQueue
{
private:
    std::vector<Element<T>> queue;
    
public:
    PriorityQueue()
    {
    }
    
    void enqueue(T value, int pri)
    {
        Element<T> elem {value, pri};
        typename std::vector< Element <T>>::iterator it;
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
    
    T dequeue()
    {
        if (queue.empty())
        {
            throw -1;
        }
        T temp = queue.back().data;
        queue.pop_back();
        return temp;
    }
    
    T first()
    {
        return queue.back().data;
    }
    
    T rear()
    {
        return queue.front().data;
    }
    
    void display()
    {
        std::cout << "] ";
        for (auto it = queue.rbegin(); it != queue.rend(); it++)
        {
            std::cout << it->data << " ";
        }
        std::cout << "]" << std::endl;
    }
};



int main() 
{
    PriorityQueue<int> q;
    q.enqueue(1, 1);
    q.enqueue(2, 2);
    q.enqueue(10, 10);
    q.enqueue(200, 200);
    
    q.display();
    std::cout << q.first() << std::endl;
    std::cout << q.rear() << std::endl;
    std::cout << q.dequeue() << std::endl;
    
    q.display();
    
    return 0;
}