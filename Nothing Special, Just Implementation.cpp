#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<long long>> &adj, vector<bool> &visited, long long u, long long &cnt) {
    visited[u] = true;
    cnt++;
    for (auto v : adj[u]) {
        if (!visited[v]) dfs(adj, visited, v, cnt);
    }
}

vector<vector<long long>> buildAdj(const vector<pair<long long,long long>> &edges, long long N) {
    vector<vector<long long>> adj(N+1);
    for (auto [a,b] : edges) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return adj;
}

int main() {
    long long N;
    cin >> N;
    vector<pair<long long,long long>> edges;
    for (long long i = 0; i < N-1; i++) {
        long long a,b;
        cin >> a >> b;
        edges.push_back({a,b});
    }
    long long Q;
    cin >> Q;
    while (Q--) {
        long long u,v,x,y;
        cin >> u >> v >> x >> y;
        vector<pair<long long,long long>> newEdges;
        for (auto [a,b] : edges) {
            if ((a==u && b==v) || (a==v && b==u)) continue;
            newEdges.push_back({a,b});
        }
        newEdges.push_back({x,y});
        auto adj = buildAdj(newEdges, N);
        vector<bool> visited(N+1,false);
        long long cnt = 0;
        dfs(adj, visited, 1, cnt);
        if (cnt == N) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
