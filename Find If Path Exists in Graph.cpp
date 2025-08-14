class Solution {
public:
    bool baglanti(vector<vector<int>> &adj, int source, int destination, int gezen){
        if(gezen == destination) return true;
        stack<int> dolap;
        int n = adj.size();
        vector<bool> visited(n, false);
        dolap.push(gezen);
        visited[gezen] = true;
        while(!dolap.empty()){
            gezen = dolap.top();
            dolap.pop();
            if(gezen == destination) return true;
            for(int z : adj[gezen]){
                if(!visited[z]){
                    dolap.push(z); 
                    visited[z] = true;
                } 
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); ++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        if(baglanti(adj, source, destination, source)) return true;
        return false;
    }
};
