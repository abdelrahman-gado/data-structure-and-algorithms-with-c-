#include <iostream>
#include <list>
#include <stack>

class Graph
{
private:
    int vertices;
    std::list<int> *adj;
    
public:
    Graph(int v)
    {
        vertices = v;
        adj = new std::list<int>[vertices];
    }
    
    void addEdges (int from, int to)
    {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    void dfs (int s)
    // s  is the start point of dfs search
    {
        bool *visited = new bool[vertices];
        for (int i {0}; i < vertices; i++)
            visited[i] = false;
        
        std::stack<int> stack;
        stack.push(s);
        visited[s] = true;
        
        while (!stack.empty())
        {
            int current_vertex = stack.top();
            stack.pop();
            std::cout << current_vertex << " ";
            std::list<int> childs_list = adj[current_vertex];
            for (auto it = childs_list.begin(); it != childs_list.end(); it++)
            {
                if (visited[*it] == false)
                {
                    stack.push(*it);
                    visited[*it] = true;
                }
            }
            
        }
        
    }
};

int main() 
{
    Graph g (4);
    g.addEdges(0, 1);
    g.addEdges(1, 2);
    g.addEdges(2, 3);
    g.addEdges(3, 0);
    
    g.dfs(0);
    
    return 0;
}