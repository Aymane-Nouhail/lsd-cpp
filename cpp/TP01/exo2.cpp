//number of groups, dfs
#include <iostream>
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

// Visited array to keep track of visited nodes
vector<bool> vis(100,false);

// Depth-first search function
void dfs(graph G, int u){
    vis[u] = true;
    for (unsigned int i = 0; i < G.num_nodes; i++){
        int v = G.adjacency_matrix[u][i];
        if (!vis[v]) {
            dfs(G,v);
        }
    }
}


int main() {
    int n;
    // Read number of vertices
    cout<<"How many nodes : ";
    cin >> n;
    graph G(n);
    // Read adjacency matrix and build adjacency list
    cout<<"Enter the matrix : "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            G.adjacency_matrix[i][j] = 1;
        }
    }
    // Count number of connected components
    int count = 0;
    // Iterate through all nodes in the graph
    for (int i = 0; i < n; i++){
        // If the node has not been visited, it is part of a new connected component
        if (!vis[i]) {
            // Start a new connected component by performing a dfs on this node
            dfs(G,i);
            // Increment the count of connected components
            count++;
        }
    }
    // Print result
    cout << count << endl;
    return 0;
}

