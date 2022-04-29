#include <iostream>
#include <string>
#include <iomanip>

// stack implementation with linked list

template <typename T>
struct Node
{
    T value;
    Node *next;
    
    Node(T value, Node *next) 
        : value {value}, next {next}
    {
        
    }
    
};

template <typename T>
class Stack
{
private:
    Node<T> *top;
    Node<T> *bottom;
    int length;
    
public:
    
    Stack()
        : top {nullptr}, bottom {nullptr}, length {0}
    {
        
    }
    
    Stack(T val)
    {
        Node<T> *newNode = new Node<T> {val, nullptr};
        top = bottom = newNode;
        length = 1;
    }
    
    T peek()
    {
        return top->value;
    }
    
    void push(T val)
    {
        Node<T> *newNode = new Node<T> {val, nullptr};
        if (isEmpty())
        {
            top = bottom = newNode;
            length = 1;
            return;
        }
        
        newNode->next = top;
        top = newNode;
        length++;
    }
    
    void pop()
    {
        if (isEmpty())
        {
            std::cout << "The stack is already empty" << std::endl;
            return;
        }
        
        if (length == 1)
        {
            bottom = nullptr;
        }
        
        Node<T> *temp = top->next;
        delete top;
        top = temp;
        length--;
    }
    
    bool isEmpty()
    {
        return (length == 0);
    }
    
    void display()
    {
        if (isEmpty())
        {
            std::cout << "The stack is empty" << std::endl;
            return;
        }
        
        Node<T> *temp = top;
        while (temp != nullptr)
        {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
    }
    
    T getTop()
    {
        if (top == nullptr)
            return "nullptr";
        
        return top->value;
    }
    
    T getBottom()
    {
        if (bottom == nullptr)
            return "nullptr";
        
        return bottom->value;
    }
    
    int getLength()
    {
        return length;
    }
    
    ~Stack()
    {
        Node<T> *temp = top;
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
    
    Stack<std::string> websites_stack;
    websites_stack.push("Google");
    websites_stack.push("Udemy");
    websites_stack.push("Discord");
    
    websites_stack.display();
    std::cout << std::endl;
    
    websites_stack.pop();
    websites_stack.pop();
    websites_stack.pop();
    
    websites_stack.display();
    std::cout << std::endl;
    
    
    std::cout << websites_stack.getTop() << std::endl;
    std::cout << websites_stack.getBottom() << std::endl;
    std::cout << "size: " << websites_stack.getLength() << std::endl;
    std::cout << std::boolalpha;
    std::cout << "isEmpty: " << websites_stack.isEmpty() << std::endl;
    
    return 0;
}