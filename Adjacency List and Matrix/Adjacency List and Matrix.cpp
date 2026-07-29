#include <bits/stdc++.h>

using namespace std;
void listt(long long u, long long v, vector<vector<long long>> &listed){
    listed[u - 1].push_back(v);
    listed[v - 1].push_back(u);
}
int main() {
    long long N, M;
    cin >> N >> M;
    long long u, v;
    vector<vector<long long>> matrix(N, vector<long long> (N, 0));
    long long i, j;
    vector<vector<long long>> listed(N);
    for(i = 0; i < M; i++){
        cin >> u >> v;
        matrix[u - 1][v - 1] = 1;
        matrix[v - 1][u - 1] = 1;
        listt(u, v, listed);
    }
    for(i = 0; i < N; i++){
        sort(listed[i].begin(), listed[i].end());
        for(j = 0; j < listed[i].size(); j++){
            cout << listed[i][j] << " ";
        }
        cout << endl;
    }
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
