#include <iostream>

struct node
{
    int data;
    node *next;
};

class MyLinkedList
{
private:
    node *head;
    node *tail;
    int size;
    
public:
    

    MyLinkedList(int value)
    {
        head = new node {value, nullptr};
        tail = head;
        size = 1;
    }
    
    void append(int value)
    {
        node *newTail = new node {value, nullptr};
        tail->next = newTail;
        tail = newTail;
        size++;
    }
    
    void prepend(int value)
    {
        node *newHead = new node {value, head};
        head = newHead;
        size++;
    }
    
    void print_linked_list()
    {
        node *temp = head;
        for (int i {0}; i < size; i++)
        {
            std::cout << "|" << temp->data << "| ";
            std::cout << "--> ";
            if (temp->next == nullptr)
            {
                std::cout << "-|||" << std::endl;
            }
            temp = temp->next;
        }
    }
    
    void insert(int index, int value)
    {
        if (index <= 0)
        {
            prepend(value);
            return;
        }
        
        if (index >= size)
        {
            append(value);
            return;
        }
        
        node *newNode = new node {value, nullptr};
        int current_i = 0;
        node *temp = head;
        while (current_i != index-1)
        {
            temp = temp->next;
            current_i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        
        std::cout << tail->data << std::endl;
    }

// another solution to insert method    
//    void insert(int index, int value)
//    {
//        if (index <= 0)
//        {
//            prepend(value);
//            return;
//        }
//        
//        node *newNode = new node {value, nullptr};
//        node *temp = head;
//        for (int i {1}; i < index; i++)
//        {
//            temp = temp->next;
//        }
//        newNode->next = temp->next;
//        temp->next = newNode;
//        size++;
//    }

// Remove method with one pointer
    void remove (int index)
    {
        node *temp = head;
        
        if (index <= 0)
        {
            head = temp->next;
            delete temp;
            size--;
            return;
        }
        
        int current_i = 0;
        while (current_i != index-1 && index-1 >= 0 && temp->next != nullptr)
        {
            temp = temp->next;
            current_i++;
        }
        
        node *deleted_node = temp->next;
        temp->next = deleted_node->next;
        if (deleted_node == tail)
        {
            tail = temp;
        }
        
        delete deleted_node;
        size--;
    }
    
    void reverse ()
    {
        if (size == 1)
        {
            return;
        }
        else
        {
            node *first = head;
            tail = head;
            node *second = head->next;
            while (second != nullptr)
            {
                node *temp = second->next;
                second->next = first;
                first = second;
                second = temp;
            }
            head->next = nullptr;
            head = first;
        }
    }


// Another solution using two pointers
//    void remove (int index)
//    {
//        
//        node *previous_node = head;
//        node *current_node = head->next;
//        
//        if (index <= 0)
//        {
//            head = current_node;
//            delete previous_node;
//            size--;
//            return;
//        }
//        
//        int current_i = 0;
//        while (current_i != index-1 && index-1 >= 0)
//        {
//            node *temp = current_node->next;
//            previous_node = current_node;
//            current_node = temp;
//            current_i++;
//        }
//        
//        previous_node->next = current_node->next;
//        delete current_node;
//        size--;
//        
//    }
    
    
    int getSize()
    {
        return size;
    }
    
    ~MyLinkedList()
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            node *temp2 = temp->next;
            delete temp;
            temp = nullptr;
            temp = temp2;
        }
    }
    
};

int main() 
{
    MyLinkedList mylinkedlist {20};
    mylinkedlist.append(200);
    mylinkedlist.append(300);
    mylinkedlist.print_linked_list();
    
    mylinkedlist.prepend(500);
    mylinkedlist.prepend(100);
    mylinkedlist.print_linked_list();
    
    mylinkedlist.insert(5, 1000);
    mylinkedlist.print_linked_list();
    
    mylinkedlist.reverse();
    mylinkedlist.print_linked_list();
    
    std::cout << mylinkedlist.getSize() << std::endl;
    
    return 0;
}