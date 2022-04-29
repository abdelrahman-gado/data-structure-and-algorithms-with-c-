#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node *next;
};

//dequeue          enqueue
// 50->20->30->40->10
//first            last
    
template <typename T>
class Queue
{
private:
    Node<T> *first;
    Node<T> *last;
    int length;
    
public:

    Queue()
        : first {nullptr}, last {nullptr}, length {0}
    {
        
    }
    
    Queue(T val)
    {
        Node<T> *newNode = new Node<T> {val, nullptr};
        first = newNode;
        last = newNode;
        length = 1;
    }
    
    T peek()
    {
        return first->value;
    }
    
    void enqueue(T val)
    {
        Node<T> *newNode = new Node<T> {val, nullptr};
        if (isEmpty())
        {
            first = last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }
    
    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        else
        {
            Node<T> *temp = first;
            first = first->next;
            if (length == 1)
            {
                last = nullptr;
            }
            delete temp;
            length--;
        }
    }
    
    
    bool isEmpty()
    {
        return (length == 0);
    }
    
    T getLast()
    {
        return last->value;
    }
    
    int getLength()
    {
        return length;
    }
    
    void display()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        else
        {
            Node<T> *temp = first;
            while (temp != nullptr)
            {
                std::cout << temp->value << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }
    
    ~Queue()
    {
        Node<T> *temp = first;
        while (temp != nullptr)
        {
            Node<T> *temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }

};

int main() 
{
    Queue<std::string> queue;
    queue.enqueue("Joy");
    queue.enqueue("Matt");
    queue.enqueue("pavel");
    queue.enqueue("Samir");
    
    queue.display();
    
    std::cout << "size: " << queue.getLength() << std::endl;
    
    std::cout << "peek: " << queue.peek() << std::endl;
    std::cout << "last: " << queue.getLast() << std::endl;
    
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