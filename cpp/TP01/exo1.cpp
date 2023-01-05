#include <iostream>
#include <list>
#include <queue>
#include <vector>


using namespace std;

struct graph
{
    vector<vector<int>> adjacency_matrix;
    int num_nodes;
};

// This function returns a list of all nodes that are directly connected to the input node
list<int> node_neighbors(int node, graph M)
{
    list<int> neighbors;
    for (int i = 0; i < M.num_nodes; i++)
    {
        if (M.adjacency_matrix[node][i] == 1)
        {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

vector<int> solve(graph G, int s)
{
    queue<int> Q;
    Q.push(s);
    vector<bool> visited(G.num_nodes, false);
    visited[s] = true;
    vector<int> prev(G.num_nodes, -1);
    int node;
    while (!Q.empty())
    {
        node = Q.front();
        Q.pop();
        list<int> neighbors = node_neighbors(node, G);
        for (auto next : neighbors)
        {
            if (visited[next] == false)
            {
                Q.push(next);
                visited[next] = true;
                prev[next] = node;
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
    vector<int> prev = solve(G, s);
    list<int> res = reconstructPath(s, e, prev);
    cout << "The shortest path is " << res.front() << " steps long." << endl;
    res.pop_front();
    return res;
}

int main()
{
    int num_nodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> num_nodes;

    graph G;
    G.num_nodes = num_nodes;
    G.adjacency_matrix.resize(num_nodes);
    for (int i = 0; i < num_nodes; i++)
    {
        G.adjacency_matrix[i].resize(num_nodes);
    }

    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 0; i < num_nodes; i++)
    {
        for (int j = 0; j < num_nodes; j++)
        {
            cin >> G.adjacency_matrix[i][j];
        }
    }

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
