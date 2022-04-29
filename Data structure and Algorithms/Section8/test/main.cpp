#include <iostream>

struct Node
{
    int value;
    Node *next;
};

class MyLinkedList {
    
private:
    Node *head;
    Node *tail;
    int size;
    
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() 
    {
        head = tail = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        Node *temp = head;
        for (int i {0}; i < index; i++)
        {
            temp = temp->next;
        }
        
        if (temp != nullptr)
            return temp->value;
        else
            return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {   
        Node *newNode = new Node {val, head};
        // if the head and tail is nullptr
        if (size == 0)
        {
            head = tail = newNode;
            size++;
            return;
        }
        
        head = newNode;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        Node *newNode = new Node {val, nullptr};
        // if the head and tail is nullptr
        if (size == 0)
        {
            tail = head = newNode;
            size++;
            return;
        }
        
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        
        if (index > size)
        {
            return;
        }
        
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        
        Node *newNode = new Node {val, nullptr};
        Node *temp = head;
        for (int i {0}; i < index-1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        
        Node *temp = head;
        for (int i {0}; i < index-1; i++)
        {
            temp = temp->next;
        }
        Node *deleted_node = temp->next;
        if (deleted_node == tail)
        {
            tail = temp;
        }
        temp->next = deleted_node->next;
        delete deleted_node;
        size--;
    }
    
    ~MyLinkedList()
    {
        Node *temp1 = head;
        while (temp1 != nullptr)
        {
            Node *temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }
    }
};

int main() 
{
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->deleteAtIndex(0);
    return 0;
}