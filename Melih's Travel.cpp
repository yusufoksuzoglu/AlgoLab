#include <bits/stdc++.h>
using namespace std;
//time limit sorunu var; daha verimli bir yol izlenebilir. (ör: set)
vector<int> kopuk(vector<vector<int>> &adj, vector<bool> &visited){
    vector<int> ayrik;
    for(int i = 0; i < adj.size(); ++i){
        if(!visited[i]) ayrik.push_back(i);
    }
    sort(ayrik.begin(), ayrik.end());
    return ayrik;
}

vector<int> travel(vector<vector<int>> &adj, vector<bool> &visited, int k){
    vector<int> answer;
    answer.push_back(k);
    visited[k] = true;

    while(answer.size() < adj.size()){
        int i = adj[k].size() - 1;
        while(i >= 0 && visited[adj[k][i]]) i--;
        if(i >= 0){
            k = adj[k][i];
            answer.push_back(k);
            visited[k] = true;
        } else {
            vector<int> ayrik = kopuk(adj, visited);
            if(!ayrik.empty()){
                k = ayrik[0];
                answer.push_back(k);
                visited[k] = true;
            } else break;
        }
    }

    return answer;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edges(M, vector<int>(2));
    int a, b;
    for(int i = 0; i < M; ++i){
        cin >> a >> b;
        edges[i][0] = a;
        edges[i][1] = b;
    }

    vector<vector<int>> adj(N);
    for(auto edge : edges){
        adj[edge[0]-1].push_back(edge[1]-1);
        adj[edge[1]-1].push_back(edge[0]-1);
    }

    for(int i = 0; i < N; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> visited(N, false);
    vector<int> answer = travel(adj, visited, 0);

    for(int i = 0; i < answer.size(); ++i){
        cout << answer[i]+1 << " ";
    }
    cout << "\n";

    return 0;
}

