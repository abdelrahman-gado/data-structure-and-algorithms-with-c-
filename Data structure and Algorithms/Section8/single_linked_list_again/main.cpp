#include <iostream>


template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class SinglyLinkedList
{
    
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
    
public:

    SinglyLinkedList ()
        : head {nullptr}, tail {nullptr}, size {0}
    {}
    
    SinglyLinkedList(T value)
    {
        Node<T> *newNode = new Node<T> {value, nullptr};
        head = newNode;
        tail = newNode;
        size = 1;
    }
    
    void prepend (T value)
    {
        Node<T> *newNode = new Node<T> {value, nullptr};
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    
    void append (T value)
    {
        Node<T> *newNode = new Node<T> {value, nullptr};
        if (size == 0)
        {
            tail = newNode;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void insert (int pos, T value)
    {
        if (pos < 0)
        {
            std::cout << "invalid index" << std::endl;
            return;
        }
        
        if (pos == 0 || (size == 0 && size >= 0))
        {
            prepend(value);
            return;
        }
        
        if (pos >= size || size == 0)
        {
            append(value);
            return;
        }
        
        Node<T> *inserted_node = new Node<T> {value, nullptr};
        Node<T> *temp = head;
        
        for (int i {0}; i < pos-1; i++)
        {
            temp = temp->next;
        }
        
        inserted_node->next = temp->next;
        temp->next = inserted_node;
        size++;
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
            Node<T> *deleted_head = head;
            head = head->next;
            delete deleted_head;
            size--;
            return;
        }
        
        
        Node<T> *temp = head;
        int current_i {0};
        
        while (current_i < pos-1)
        {
            temp = temp->next;
            current_i++;
        }
        
        Node<T> *deleted_node = temp->next;
        temp->next = deleted_node->next;
        if (deleted_node == tail)
        {
            tail = temp;
        }
        delete deleted_node;
        size--;
    }
    
    
    void display_linked_list()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    
    int getSize()
    {
        return size;
    }
    
    T getHeadValue()
    {
        return head->data;
    }
    
    T getTailValue()
    {
        return tail->data;
    }
    
    
    ~SinglyLinkedList()
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            Node<T> *current_node = temp;
            temp = current_node->next;
            delete current_node;
            current_node = nullptr;
        }
    }
    
};



int main() 
{
    SinglyLinkedList<int> list;
    list.prepend(12);
    list.prepend(13);
    list.prepend(1299);
    
    list.append(100);
    list.append(10000);
    
    list.display_linked_list();
    
    list.insert(-200, 300);
    list.insert(0, 30003);
    list.display_linked_list();
    list.insert(2, 33);
    list.display_linked_list();
    list.insert(1, 222);
    list.display_linked_list();
    list.insert(100, 200001);
    list.display_linked_list();
    list.insert(list.getSize(), 11111);
    
    list.display_linked_list();
    
    list.remove(-200);
    list.remove(0);
    list.display_linked_list();
    list.remove(1);
    list.display_linked_list();
    list.remove(2);
    list.display_linked_list();
    list.remove(200);
    list.remove(list.getSize()-1);
    list.display_linked_list();
    
    std::cout << "Head: " << list.getHeadValue() << std::endl;
    std::cout << "Tail: " << list.getTailValue() << std::endl;
    
    return 0;
}