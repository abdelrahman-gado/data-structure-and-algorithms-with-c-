#include <iostream>
#include <iomanip>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BinarySearchTree
{
private:
    Node *root;
    
public:
    BinarySearchTree()
        : root {nullptr}
    {
    }
    
    void insert(int value)
    {
        Node *newNode = new Node {value, nullptr, nullptr};
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        
        Node *temp = root;
        while (true)
        {
            if (value > temp->data)
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
            else
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
        }
    }
    
    bool lookup(int value)
    {
        if (root == nullptr)
        {
            std::cout << "The Binary Search Tree is Empty" << std::endl;
            return false;
        }
        
        Node *temp = root;
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
    
    void display(Node *node)
    {
        if (node)
        {
            display(node->left);
            display(node->right);
            std::cout << node->data << " ";
        }
    }
    
    void display_tree()
    {
        display(root);
        std::cout << std::endl;
    }
    
    void recusive_delete(Node *node)
    {
        if (node)
        {
            recusive_delete(node->left);
            recusive_delete(node->right);
            delete node;
        }
    }
    
    ~BinarySearchTree()
    {
        recusive_delete(root);
    }
};


int main() 
{
    BinarySearchTree tree;
    tree.insert(9);
    tree.insert(20);
    tree.insert(4);
    tree.insert(170);
    tree.insert(15);
    tree.insert(6);
    tree.insert(3);
    
    tree.display_tree();
    
    std::cout << std::boolalpha;
    std::cout << tree.lookup(9) << std::endl;
    std::cout << tree.lookup(170) << std::endl;
    std::cout << tree.lookup(120) << std::endl;
    
    return 0;
}