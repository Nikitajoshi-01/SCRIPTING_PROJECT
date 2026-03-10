#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
    queue<int>q;
    int src;
    cout<<"enter the source node"<<endl;
    cin>>src;
    vector<vector<int>>ans;
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
        }
       temp.push_back(node);
    }
    ans.push_back(temp);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();i++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}