#include <bits/stdc++.h>
using namespace std;

//UNDIRECTED GRAPH :
bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    for (int neigh : adj[node]) {
        if (!vis[neigh]) {
            if (dfs(neigh, node, adj, vis))
                return true;
        }
        else if (neigh != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cout<<"the number of vertices nad no of edges"<<endl;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis)) {
                cout << "Cycle detected\n";
                return 0;
            }
        }
    }
    cout << "No cycle\n";
}
