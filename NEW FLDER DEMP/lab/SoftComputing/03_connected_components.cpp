#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>>&adj,int src, vector<bool>&vis,vector<vector<int>>&ans){
    queue<int>q;
    q.push(src);
    vis[src]=1;
    int lvl=0;
    while(!q.empty()){
        vector<int>temp;
        int size=q.size();
        while(size--){
        int node=q.front();
        q.pop();
        for(auto i : adj[node]){
            if(!vis[i])
            q.push(i);
            vis[i]=1;
        }
       temp.push_back(node);
    }
    ans.push_back(temp);
    }
}
   
int main(){
    int n;
    cout<<"no of nodes"<<endl;
    cin>>n;
    //n = no of  nodes:
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        int a;
        cout<<"no of adj nodes"<<endl;
        cin>>a;
        
        while(a--){
        int node;
        cout<<"enter adj node"<<endl;
        cin>>node;
        adj[i].push_back(node);

        }
    }
    vector<bool>vis(n,0);
     int src;
    cout<<"enter source"<<endl;
    cin>>src;

    vector<vector<int> > ans;
    int connectedcomp=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
        bfs(adj,i,vis,ans);
        connectedcomp++;
        }
    }
    //  for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<connectedcomp<<endl;
    
}