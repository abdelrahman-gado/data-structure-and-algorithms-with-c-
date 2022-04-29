#include <iostream>
#include <string>
#include <vector>

struct node
{
    std::string key = "";
    int value;
    node *next = nullptr;
};


class HashTable
{
private:
    int size;
    node* data;
    int _hash(std::string key)
    {
        int hash = 0;
        for (int i {0}; i < key.size(); i++)
        {
            hash = (hash + key[i] * i) % size;
        }
        
        return hash;
    }
    
public:
    HashTable(int size) : size {size}
    {
        data = new node[size];
    }
    
    
    void set(std::string key, int value)
    {
        int address = _hash(key);
        if (data[address].key == "")
        {
            data[address].key = key;
            data[address].value = value;
            data[address].next = nullptr;
        }
        else
        {
            node *next_node = new node;
            next_node->key = key;
            next_node->value = value;
            next_node->next = nullptr;
            node *temp = data[address].next;
            data[address].next = next_node;
            next_node->next = temp;
            temp = nullptr;
        }
        
    }
    
    int get(std::string key)
    {
        int address = _hash(key);
        if (data[address].key == "")
        {
            return -1;
        }
        else
        {
            if (data[address].next == nullptr)
            {
                return data[address].value;
            }
            else
            {
                node *temp = &(data[address]);
                while (temp != nullptr)
                {
                    if (key == temp->key)
                        return temp->value;
                    
                    temp = temp->next;
                }
            }
        }
        
        return -1;
    }
    
    std::vector<std::string> keys()
    {
        std::vector<std::string> total_keys;
        for (int i {0}; i < size; i++)
        {
            if (data[i].key != "")
            {
                node *temp = &(data[i]);
                while (temp != nullptr)
                {
                    total_keys.push_back(temp->key);
                    temp = temp->next;
                }
            }
        }
        return total_keys;
    }
    
    std::vector<int> values()
    {
        std::vector<int> vals;
        for (int i {0}; i < size; i++)
        {
            if (data[i].key != "")
            {
                node *temp = data+i;
                while (temp != nullptr)
                {
                    vals.push_back(temp->value);
                    temp = temp->next;
                }
                
            }
        }
        return vals;
    }
    
    void display()
    {
        for (int i {0}; i < size; i++)
        {
            if (data[i].key == "")
            {
                std::cout <<  "EMPTY BUCKET" << std::endl; 
            }
            else
            {
                node *temp = &(data[i]);
                while (temp != nullptr)
                {
                    std::cout << "|" << temp->key << " : " << temp->value << "| ---->";
                    temp = temp->next;
                }
                std::cout << "#####" << std::endl;
            }
        }
    }
    
    

    ~HashTable()
    {
        delete [] data;
    }
};


int main() 
{
    HashTable myHashTable {3};
    myHashTable.set("grapes", 10000);
    myHashTable.set("apples", 9000);
    myHashTable.set("pears", 2000);
    myHashTable.set("grapes", 30000);
    myHashTable.set("grapes", 50000);
    myHashTable.set("grapes", 70000);
    
    myHashTable.display();
    
    std::vector<std::string> keys = myHashTable.keys();
    for (auto k : keys)
    {
        std::cout << k << "  ";
    }
    std::cout << std::endl;
    
    std::vector<int> values = myHashTable.values();
    for (auto v : values)
    {
        std::cout << v << "  ";
    }
    
    std::cout << myHashTable.get("grapes") << std::endl;
    std::cout << myHashTable.get("apples") << std::endl;
    std::cout << myHashTable.get("pears") << std::endl;
    
    
    return 0;
}