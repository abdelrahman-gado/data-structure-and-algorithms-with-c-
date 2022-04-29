#include <iostream>
#include <map>
#include <vector>

class Graph
{
private:
    int numberOfNodes;
    std::map<int, std::vector<int>> adjacent_list;
    
public:
    Graph()
    {
        
    }
    
    void addVertex(int node_value)
    {
        adjacent_list[node_value] = std::vector<int> {};
        numberOfNodes++;
    }
    
    
    void addEdge(int from_node, int to_node)
    {
        adjacent_list[from_node].push_back(to_node);
        adjacent_list[to_node].push_back(from_node);
    }
    
    void showConnections()
    {
        for (auto it = adjacent_list.begin(); it != adjacent_list.end(); it++)
        {
            std::cout << it->first << " --> ";
            for (int i {0}; i < (it->second).size(); i++)
            {
                std::cout << (it->second)[i] << " ";
            }
            std::cout << std::endl;
        }
    }
    
};

int main() 
{
    Graph graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addVertex(6);
    graph.addEdge(3, 1);
    graph.addEdge(3, 4);
    graph.addEdge(4, 2);
    graph.addEdge(4, 5);
    graph.addEdge(1, 2);
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(6, 5);
    
    graph.showConnections();
    
    
    
    return 0;
}