#include <iostream>
#include <vector>

using namespace std;

// Number of vertices
int n;

// Adjacency list representation of the graph
vector<int> adj[100];

// Visited array to keep track of visited nodes
bool vis[100];

// Depth-first search function
void dfs(int u){
    // Mark node as visited
    vis[u] = true;

    // Visit all unvisited neighbors
    // Iterate through the adjacency list of node u
    for (unsigned int i = 0; i < adj[u].size(); i++){
        // Get the current neighbor
        int v = adj[u][i];
        // If the neighbor has not been visited, perform a dfs on it
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    // Read number of vertices
    cout<<"How many nodes : ";
    cin >> n;

    // Read adjacency matrix and build adjacency list
    cout<<"Enter the matrix : "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            if (x) {
                // Add edge between i and j
                adj[i].push_back(j);
            }
        }
    }
    // Count number of connected components
    int count = 0;
    // Iterate through all nodes in the graph
    for (int i = 0; i < n; i++){
        // If the node has not been visited, it is part of a new connected component
        if (!vis[i]) {
            // Start a new connected component by performing a dfs on this node
            dfs(i);
            // Increment the count of connected components
            count++;
        }
    }
    // Print result
    cout << count << endl;
    return 0;
}

