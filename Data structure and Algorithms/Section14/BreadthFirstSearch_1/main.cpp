#include <iostream>
#include <stack>
#include <vector>
#include <queue>

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
    {}
    
    void insert(int value)
    {
        Node *newNode = new Node {value, nullptr, nullptr};
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        
        Node *temp1 = nullptr;
        Node *temp2 = root;
        while (temp2 != nullptr)
        {
            temp1 = temp2;
            if (value > temp2->data)
                temp2 = temp2->right;
            else if (value < temp2->data)
                temp2 = temp2->left;
            
        }
        
        if (value > temp1->data)
            temp1->right = newNode;
        else if (value < temp1->data)
            temp1->left = newNode;
        
    }
    
    bool lookup(int value)
    {
        if (root == nullptr)
        {
            std::cout << "Tree is Empty, please insert values" << std::endl;
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
    
    void remove (int value)
    {
        if (root == nullptr)
        {
            std::cout << "Binary Search Tree is Empty" << std::endl;
            return;
        }
        
        Node *temp1 = nullptr;
        Node *temp2 = root;
        
        while (temp2 != nullptr)
        {
            Node *temp3 = temp2;
            if (value > temp2->data)
                temp2 = temp2->right;
            else if (value < temp2->data)
                temp2 = temp2->left;
            else if (value == temp2->data)
                break;
            temp1 = temp3;
        }
        
        if (temp2 == nullptr)
        {
            std::cout << "this value isn't in the tree" << std::endl;
            return;
        }
        else
        {
            if (temp2->right == nullptr && temp2->left == nullptr)
            {
                Node *del_node = temp2;
                if (temp1->right == temp2)
                {
                    temp1->right = nullptr;
                }
                else
                {
                    temp1->left = nullptr;
                }
                delete del_node;
            }
            else if (temp2->right != nullptr)
            {
                Node *right_node = temp2->right;
                Node *del_node = temp2;
                if (right_node->left == nullptr)
                {
                    if (temp1->right == temp2)
                    {
                        temp1->right = right_node;
                    }
                    else
                    {
                        temp1->left = right_node;
                    }
                    right_node->left = del_node->left;
                    delete del_node;
                }
                else
                {
                    Node *last_last_node = nullptr;
                    Node *last_left_node = right_node;
                    while (last_left_node->left != nullptr)
                    {
                        last_last_node = last_left_node;
                        last_left_node = last_left_node->left;
                    }
                    
                    last_last_node->left = nullptr;
                    
                    if (temp1->right == temp2)
                    {
                        temp1->right = last_left_node;
                    }
                    else
                    {
                        temp1->left = last_left_node;
                    }
                    last_left_node->left = del_node->left;
                    last_left_node->right = del_node->right;
                    
                    delete del_node;
                }
                
            }
            else if (temp2->left != nullptr && temp2->right == nullptr)
            {
                Node *del_node = temp2;
                if (temp1->right == temp2)
                {
                    temp1->right = temp2->left;
                }
                else
                {
                    temp2->left = temp2->left;
                }
                delete del_node;
            }
            
        }
        
    }
    
    void display()
    {
        std::stack<Node *> s;
        Node *temp = root;
        
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
        std::cout << std::endl;
    }
    
    void delete_recursive(Node *node)
    {
        if (node)
        {
            delete_recursive(node->left);
            delete_recursive(node->right);
            delete node;
        }
    }
    
    std::vector<int> breadthFirstSearch (Node *root)
    {
        std::vector<int> bfs_list;
        std::queue<Node *> queue;
        queue.push(root);
        while (queue.size() > 0)
        {
            Node *current_node = queue.front();
            bfs_list.push_back(current_node->data);
            if (current_node->left != nullptr)
            {
                queue.push(current_node->left);
            }
            
            if (current_node->right != nullptr)
            {
                queue.push(current_node->right);
            }
            queue.pop();
        }
        
        return bfs_list;
    }
    
    Node *get_root()
    {
        return root;
    }
    
    ~BinarySearchTree()
    {
        delete_recursive(root);
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
    tree.insert(1);

    tree.display();
    
    Node *root = tree.get_root();
    std::vector<int> vec = tree.breadthFirstSearch(root);
    for (int item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    return 0;
}