#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node *next;
};

template <typename T>
class Stack
{
private:
    Node<T> *top;
    int length;
    
public:
    Stack()
        : top {nullptr}, length {0}
    {
        
    }
    
    Stack(T val)
    {
        Node<T> *newNode = new Node<T> {val, nullptr};
        top = newNode;
        length = 1;
    }
    
    T peek()
    {
        if (top == nullptr)
            throw -1;
            
        return top->value;
    }
    
    void push (T val)
    {
        Node<T> *newNode = new Node<T> {val, top};
        top = newNode;
        length++;
    }
    
    T pop()
    {
        if (isEmpty())
        {
            std::cout << "stack is empty" << std::endl;
            return NULL;
        }
        
        Node<T> *temp = top;
        T poped_val = temp->value;
        top = top->next;
        delete temp;
        length--;
        return poped_val;
    }
    
    
    int getLength()
    {
        return length;
    }
    
    bool isEmpty()
    {
        return length == 0;
    }
    
    void display()
    {
        Node<T> *temp = top;
        while(temp != nullptr)
        {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
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
    
    Stack<std::string> stack;
    stack.push("google");
    stack.push("udemy");
    stack.push("discord");
    
    stack.display();
    
    stack.pop();
    stack.pop();

    
    stack.display();
    
    std::cout << "size: " << stack.getLength() << std::endl;
    
    try
    {
        std::cout << "peek: " << stack.peek() << std::endl;
    }
    catch (int &i)
    {
        std::cout << "stack is empty, there is no peek" << std::endl;
        return 0;
    }
    
    return 0;
}