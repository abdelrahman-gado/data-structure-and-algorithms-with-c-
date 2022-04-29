#include <iostream>
#include <stack>
#include <list>
#include <queue>

class Graph
{
private:
    int vertices;
    std::list<int> *adj;
    bool *visited;
    
public:
    Graph (int v)
    {
        vertices = v;
        adj = new std::list<int> [vertices];
        visited = new bool[vertices];
        for (int i {0}; i < vertices; i++)
        {
            visited[i] = false;
        }
    }
    
    void addEdages(int from, int to)
    {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    void bfs (int s)
    // s is the start point
    {
        bool *visited = new bool[vertices];
        for (int i {0}; i < vertices; i++)
        {
            visited[i] = false;
        }
        
        std::queue<int> queue;
        queue.push(s);
        visited[s] = true;
        
        while (!queue.empty())
        {
            int current_vertex = queue.front();
            std::cout << current_vertex << " ";
            visited[current_vertex] = true;
            std::list<int> childs_list = adj[current_vertex];
            for (auto it = childs_list.begin(); it != childs_list.end(); it++)
            {
                if (visited[*it] == false)
                {
                    queue.push(*it);
                    visited[*it] = true;
                }
            }
            
            queue.pop();
        }
        
        std::cout << std::endl;
    }
    
    void dfs_recursive (int s) // s is the start point
    {
        std::cout << s << std::endl;
        visited[s] = true;
        std::list<int> childs_list = adj[s];
        for (auto it = childs_list.begin(); it != childs_list.end(); it++)
        {
            if (visited[*it] == false)
                dfs_recursive(*it);
        }
        
    }
    
    void dfs_iterative (int s) // time O(n) -- space O(h)
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
            std::cout << current_vertex << " ";
            stack.pop();
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


        std::cout << std::endl;
    }
    
};

int main() 
{
    
    Graph g (4);
    g.addEdages(0, 1);
    g.addEdages(1, 2);
    g.addEdages(2, 3);
    g.addEdages(3, 0);
    
    g.dfs_iterative(0);
    
    return 0;
}