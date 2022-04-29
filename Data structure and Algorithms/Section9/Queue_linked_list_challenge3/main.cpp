#include <iostream>
#include <string>

struct Node
{
    std::string value;
    Node *next;
};

class Queue
{
private:
    Node *first;
    Node *last;
    int length;
    
public:

    Queue()
        : first {nullptr}, last {nullptr}, length {0}
    {
        
    }
    
    Queue(std::string val)
    {
        Node *newNode = new Node {val, nullptr};
        first = last = newNode;
        length = 1;
    }
    
    std::string peek()
    {
        if (isEmpty())
        {
            return "Queue is empty";
        }
        return first->value;
    }
    
    void enqueue(std::string val)
    {
        Node *newNode = new Node {val, nullptr};
        if (isEmpty())
        {
            length = 1;
            last = first = newNode;
            return;
        }
        
        last->next = newNode;
        last = newNode;
        length++;
    }
    
    std::string dequeue()
    {
        if (isEmpty())
        {
            return "Queue is empty";
        }
        
        Node *temp = first;
        std::string val_temp = temp->value;
        first = first->next;
        if (length == 1)
        {
            last = nullptr;
        }
        delete temp;
        length--;
        return val_temp;
    }
    
    
    bool isEmpty()
    {
        return (length == 0);
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
        
        Node *temp = first;
        while (temp != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
    
    std::string getLast()
    {
        if (isEmpty())
        {
            return "Queue is empty";
        }
        
        return last->value;
    }
    
    
    ~Queue()
    {
        Node *temp = first;
        while (temp != nullptr)
        {
            Node *temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        
    }
    
};


int main() 
{
    Queue q;
    q.enqueue("Joy");
    q.enqueue("Matt");
    q.enqueue("Pavel");
    q.enqueue("Samir");
    
    q.display();
    
    std::cout << "\n";
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    std::cout << "\n";
    
    q.display();
    
    std::cout << "size: " << q.getLength() << std::endl;
    std::cout << "first: " << q.peek() << std::endl;
    std::cout << "last: " << q.getLast() << std::endl;
    
    return 0;
}