#include <iostream>
#include <stack>
#include <vector>


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
    
    void inorder (Node *root, std::vector<int> &list)
    {
        if (root == nullptr)
            return;
        
        inorder(root->left, list);
        list.push_back(root->data);
        inorder(root->right, list);
    }
    
    
    std::vector<int> dfs_inorder(Node *root, std::vector<int> list)
    {
        inorder(root, list);
        return list;
    }
    
    
    void preorder (Node *root, std::vector<int> &list)
    {
        if (root == nullptr)
            return;
        
        list.push_back(root->data);
        preorder(root->left, list);
        preorder(root->right, list);
    }
    
    
    std::vector<int> dfs_preorder (Node *root, std::vector<int> list)
    {
        preorder(root, list);
        return list;
    }
    
    void postorder (Node *root, std::vector<int> &list)
    {
        if (root == nullptr)
            return;
        
        postorder(root->left, list);
        postorder(root->right, list);
        list.push_back(root->data);
    }
    
    std::vector<int> dfs_postorder (Node *root, std::vector<int> list)
    {
        postorder(root, list);
        return list;
    }
    
    
    Node *getRoot()
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

    
    Node *root = tree.getRoot();
    std::vector<int> inorder_list = tree.dfs_inorder(root, {});
    std::cout << "inorder: ";
    for (int item : inorder_list)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    
    std::vector<int> preorder_list = tree.dfs_preorder(root, {});
    std::cout << "preorder: ";
    for (int item : preorder_list)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    
    std::vector<int> postorder_list = tree.dfs_postorder(root, {});
    std::cout << "postorder: ";
    for (int item : postorder_list)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    
    
    return 0;
}