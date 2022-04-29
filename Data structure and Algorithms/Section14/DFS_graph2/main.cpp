#include <iostream>
#include <list>
#include <stack>

class Graph
{
private:
    int vertices;
    std::list<int> *adj;
    bool *visited;
    
public:
    Graph(int v)
    {
        vertices = v;
        adj = new std::list<int>[vertices];
        visited = new bool[vertices];
        for (int i {0}; i < vertices; i++)
            visited[i] = false;
    }
    
    void init_visited ()
    {
        for (int i {0}; i < vertices; i++)
            visited[i] = false;
    }
    
    
    void addEdges (int from, int to)
    {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    void dfs (int s)
    {
        visited[s] = true;
        std::list<int> childs_list = adj[s];
        std::cout << s << " ";
        for (auto it = childs_list.begin(); it != childs_list.end(); it++)
        {
            if (visited[*it] == false)
                dfs(*it);
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