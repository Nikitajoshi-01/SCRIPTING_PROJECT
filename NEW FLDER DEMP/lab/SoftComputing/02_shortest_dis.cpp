// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// int main(){
//     int n;
//     cout<<"no of nodes"<<endl;
//     cin>>n;
//     //n = no of  nodes:
//     vector<vector<int>>adj(n);
//     for(int i=0;i<n;i++){
//         int a;
//         cout<<"no of adj nodes"<<endl;
//         cin>>a;
//         while(a--){
//         int node;
//         cout<<"enter adj node"<<endl;
//         cin>>node;
//         int wt;
//         cout<<"enter weight"<<endl;
//         cin>>wt;
//         adj[i].push_back(node);
//         }
//     }
//     vector<bool>vis(n,0);
//     vector<int>dist(n,INT_MAX);
//     queue<int>q;
//     int src;
//     cout<<"enter source"<<endl;
//     cin>>src;
//     vector<vector<int> > ans;
//     q.push(src);
//     vis[0]=1;
//     dist[src]=0;
//     int lvl=0;
//     while(!q.empty()){
//         vector<int>temp;
//         int size=q.size();
//         while(size--){
//         int node=q.front();
//         q.pop();
       
//         for(auto i : adj[node]){
//             if(!vis[i]){
//             q.push(i);
//             vis[i]=1;
//             }

//         }

//        temp.push_back(node);
//     }
//     ans.push_back(temp);
//     }
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[i].size();i++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }




#include <bits/stdc++.h>
using namespace std;

vector<int> shortestDistance(int n, vector<vector<int>>& adj, int src) {
    vector<int> dist(n, -1);   
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int nbr : adj[node]) {
            if(dist[nbr] == -1) {        // not visited
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // remove if directed
    }

    int src;
    cin >> src;

    vector<int> dist = shortestDistance(n, adj, src);

    for(int i = 0; i < n; i++) {
        cout << "Distance from " << src << " to " << i << " = ";
        cout << dist[i] << endl;
    }
}
