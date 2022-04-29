#include <iostream>
#include <stack>
#include <iomanip>

template<typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;
    
    Node(T data)
        : data {data}, left {nullptr}, right {nullptr}
    {
        
    }
};


template<typename T>
class BinarySearchTree
{
private:
    Node<T> *root;
    
public:
    BinarySearchTree()
        : root {nullptr}
    {
        
    }
    
    // O(log(n))
    void insert(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        
        Node<T> *temp1 = nullptr;
        Node<T> *temp2 = root;
        while (temp2 != nullptr)
        {
            temp1 = temp2;
            if (value > temp2->data)
            {
                temp2 = temp2->right;
            }
            else
            {
                temp2 = temp2->left;
            }
        }
        
        if (temp1 == nullptr)
        {
            root = newNode;
            return;
        }
        
        if (value > temp1->data)
            temp1->right = newNode;
        else
            temp1->left = newNode;
    }
    
    // O(log(n))
    bool lookup(T value)
    {
        if (root == nullptr)
            return false;
        
        Node<T> *temp = root;
        while (temp != nullptr)
        {
            if (value > temp->data)
                temp = temp->right;
            else if (value < temp->data)
                temp = temp->left;
            else if (value == temp->data)
                return true;
        }
        
        return false;
    }
    
    void remove(int data)
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty" << std::endl;
            return;
        }
        
        Node<T> *temp = root;
        Node<T> *parent = nullptr;
        
        while (temp != nullptr)
        {
            if (data < temp->data)
            {
                parent = temp;
                temp = temp->left;
            }
            else if (data > temp->data)
            {
                parent = temp;
                temp = temp->right;
            }
            else
            {
                // delete leaf nodes
                if (temp->left == nullptr && temp->right == nullptr)
                {
                    if (parent->left == temp)
                    {
                        parent->left = nullptr;
                    }
                    else
                    {
                        parent->right = nullptr;
                    }
                    delete temp;
                    return;
                }
                // delete a parent node that have a left or right (one child)
                else if (temp->left == nullptr || temp->right == nullptr)
                {
                    if (temp->left != nullptr)            
                    {
                        parent->left = temp->left;   
                    }
                    else
                    {
                        parent->right = temp->right;   
                    }                                      
                    delete temp;
                    return;
                }
                // delete a node that have two children
                else
                {
                    Node<T> *t = temp->right;
                    if (t->left == nullptr && t->right == nullptr)
                    {
                        temp->data = t->data;
                        temp->right = nullptr;
                        delete t;
                        return;
                    }
                    else if (t->left == nullptr && t->right != nullptr)
                    {
                        temp->data = t->data;
                        temp->right = t->right;
                        delete t;
                        return;
                    }
                    else if (t->left != nullptr)
                    {
                        while (t->left != nullptr)
                        {
                            parent = t;
                            t = t->left;
                        }
                        temp->data = t->data;
                        parent->left = nullptr;
                        delete t;
                        return;
                    }
                }
            }
        }
        
    }
    
    void display()
    {
        std::stack<Node<T> *> s;
        Node<T> *temp = root;
        
        std::cout << "[ ";
        
        while (temp != nullptr || s.empty() == false)
        {
            
            while (temp != nullptr)
            {
                s.push(temp);
                temp = temp->left;
            }
            
            temp = s.top();
            std::cout << temp->data << " ";
            s.pop();
            
            temp = temp->right;
        }
        std::cout << "]" << std::endl;
    }
    
    void delete_node(Node<T> *node)
    {
        if (node)
        {
            delete_node(node->left);
            delete_node(node->right);
            delete node;
        }
    }
    
    ~BinarySearchTree()
    {
        delete_node(root);
    }
};




int main() 
{
    BinarySearchTree<int> bst;
    bst.insert(9);
    bst.insert(4);
    bst.insert(20);
    bst.insert(170);
    bst.insert(15);
    bst.insert(6);
    bst.insert(1);
    
    bst.display();
    
    std::cout << std::boolalpha;
    std::cout << bst.lookup(9) << std::endl;
    std::cout << bst.lookup(200) << std::endl;
    
    bst.remove(20);
    bst.display();
    
    return 0;
}