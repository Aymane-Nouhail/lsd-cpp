//shortest path, bfs
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class graph
{
    public:
        graph(int n) : num_nodes(n) {
            adjacency_matrix.resize(n);
            for(int i=0;i<n;i++) adjacency_matrix[i].resize(n);
        }
        vector<vector<int>> adjacency_matrix;
        int num_nodes;
};

vector<int> bfs(graph G, int s){
    queue<int> Q; Q.push(s);
    vector<bool> visited(G.num_nodes, false); visited[s] = true;
    vector<int> prev(G.num_nodes, -1);
    int node;
    while (!Q.empty())
    {
        node = Q.front();
        Q.pop();
        for (int i = 0; i < G.num_nodes; i++)
        {
            if (G.adjacency_matrix[node][i] == 1 && !visited[i])
            {
                Q.push(i);
                visited[i] = true;
                prev[i] = node;
            }
        }
    }
    return prev;
}

list<int> reconstructPath(int s, int e, vector<int> prev)
{
    list<int> path;
    int count = 0;
    for (int at = e; at != -1; at = prev[at])
    {
        path.push_front(at);
        count++;
    }
    path.push_front(count);
    return path;
}

list<int> shortestPath(graph G, int s, int e)
{
    vector<int> prev = bfs(G, s);
    list<int> res = reconstructPath(s, e, prev);
    cout << "The shortest path is " << res.front() << " steps long." << endl;
    res.pop_front();
    return res;
}

 int main(){
    graph G(6);
    G.adjacency_matrix = {{0, 1, 1, 0, 0, 0},
                          {1, 0, 1, 0, 0, 0},
                          {1, 1, 0, 1, 0, 0},
                          {0, 0, 0, 0, 1, 0},
                          {0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0}};
    int source, destination;
    cout << "Enter the source node: ";
    cin >> source;
    cout << "Enter the destination node: ";
    cin >> destination;

    list<int> shortest_path = shortestPath(G, source, destination);

    cout << "The shortest path from node " << source << " to node " << destination << " is: ";
    for (auto node : shortest_path)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


