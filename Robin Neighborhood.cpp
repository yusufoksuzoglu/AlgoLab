#include <bits/stdc++.h>

using namespace std;
void postorderr(vector<vector<long long>> &edges, vector<bool> &visited, 
                vector<vector<long long>> &dp,long long node){
    visited[node] = true;

    // root seçiliyor
    dp[node][1] = edges[node][0];

    // root seçilmiyor
    dp[node][0] = 0;

    for(long long i = 1; i < edges[node].size(); i++)
    {
        long long child = edges[node][i];
        if(!visited[child])
        {
            postorderr(edges, visited, dp, child);
            dp[node][0] += max(dp[child][0], dp[child][1]);
            dp[node][1] += dp[child][0];
        }
    }
}
int main() {
    long long n, u, v;
    cin >> n;
    vector<vector<long long>> edges(n + 1);
    for(long long i = 0; i < n - 1; ++i){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    } /* sample2: {{2,3}, {1,4,5}, {1,6,7}, {2}, {2}, {3}, {3}} */
    long long c;
    for(long long i = 1; i <= n; ++i){
        cin >> c;
        edges[i].insert(edges[i].begin(), c);//ci değerleri
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    vector<bool> visited(n + 1, false);
    postorderr(edges, visited, dp, 1);
    cout << max(dp[1][0], dp[1][1]);
	return 0;
}
