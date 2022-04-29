#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
    
public:
    DoublyLinkedList ()
        : head {nullptr}, tail {nullptr}, size {0}
    {}
    
    DoublyLinkedList (T value)
    {
        Node<T> *newNode = new Node<T> {value, nullptr, nullptr};
        head = newNode;
        tail = newNode;
        size = 1;
    }
    
    void prepend (T value)
    {
        Node<T> *newNode = new Node<T> {value, head, nullptr};
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
            size++;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
            size++;
        }
    }
    
    void append (T value)
    {
        Node<T> *newNode = new Node<T> {value, nullptr, tail};
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
            size++;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }
    
    void insert (int pos, T value)
    {
        if (pos < 0)
        {
            std::cout << "invalid index" << std::endl;
            return;
        }
        
        if (pos >= size)
        {
            append(value);
            return;
        }
        
        if (pos == 0)
        {
            prepend(value);
            return;
        }
        
        Node<T> *newNode = new Node<T> {value, nullptr, nullptr};
        Node<T> *temp = head;
        for (int i {0}; i < pos; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        (temp->prev)->next = newNode;
        temp->prev = newNode;
        
    }
    
    void remove (int pos)
    {
        if (pos < 0 || pos >= size)
        {
            std::cout << "invalid index" << std::endl;
            return;
        }
        
        if (pos == 0)
        {
            Node<T> *temp = head->next;
            delete head;
            head = temp;
            head->prev = nullptr;
            size--;
            return;
        }
        
        if (pos == size-1)
        {
            Node<T> *temp = tail->prev;
            delete tail;
            tail = temp;
            tail->next = nullptr;
            size--;
            return;
        }
        
        Node<T> *temp = head;
        for (int i {0}; i < pos; i++)
        {
            temp = temp->next;
        }
        Node<T> *leader = temp->prev;
        Node<T> *follower = temp->next;
        leader->next = follower;
        follower->prev = leader;
        delete temp;
        size--;
    }
    
    void reverse()
    {
        Node<T> *temp = nullptr;
        Node<T> *current = head;
        tail = current;
        
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        head = temp->prev;
        head->prev = nullptr;
    }
    
    int getSize()
    {
        return size;
    }
    
    T getHeadData()
    {
        return head->data;
    }
    
    T getTailData()
    {
        return tail->data;
    }
    
    void print_list()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    
    ~DoublyLinkedList()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            delete temp->prev;
            temp = temp->next;
        }
        std::cout << "the list deleted successfully" << std::endl;
    }
    
};



int main() 
{
    DoublyLinkedList<int> list {20};
    
    list.prepend(30);
    list.prepend(40);
    list.prepend(50);
    
    list.append(60);
    list.append(90);
    list.print_list();
    
    std::cout << list.getHeadData() << std::endl;
    std::cout << list.getTailData() << std::endl;
    std::cout << list.getSize() << std::endl;
    
    std::cout << std::endl << std::endl;
    
    list.reverse();
    
    
    list.print_list();
    
    std::cout << list.getHeadData() << std::endl;
    std::cout << list.getTailData() << std::endl;
    std::cout << list.getSize() << std::endl;
    
    return 0;
}