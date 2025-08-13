// Birinci Çözüm: Verimlilik olarak kötü ancak analiz açısından kıymetli

class Solution {
public:
    vector<vector<vector<pair<int, int>>>> kenarliAdj(vector<vector<vector<pair<int, int>>>> adj, vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        pair<int, int> koord;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j - 1 >= 0) {
                    koord = {i, j - 1};
                    adj[i][j].push_back(koord);
                }
                if (i - 1 >= 0) {
                    koord = {i - 1, j};
                    adj[i][j].push_back(koord);
                }
                if (j + 1 < m) {
                    koord = {i, j + 1};
                    adj[i][j].push_back(koord);
                }
                if (i + 1 < n) {
                    koord = {i + 1, j};
                    adj[i][j].push_back(koord);
                }
            }
        }
        return adj;
    }

    bool yedekdfs(vector<vector<int>> &mat, vector<vector<vector<pair<int, int>>>> &adj, pair<int, int> koord, vector<vector<bool>> &visited) {
        int n = mat.size();
        int m = mat[0].size();
        int x = koord.first, y = koord.second;

        if (x == 0 || y == 0) return true;
        visited[x][y] = true;

        for (auto &p : adj[x][y]) {
            int nx = p.first, ny = p.second;
            if (!visited[nx][ny] && mat[x][y] >= mat[nx][ny]) {
                if (yedekdfs(mat, adj, {nx, ny}, visited)) return true;
            }
        }
        return false;
    }

    bool yedekdfs2(vector<vector<int>> &mat, vector<vector<vector<pair<int, int>>>> &adj, pair<int, int> koord, vector<vector<bool>> &visited) {
        int n = mat.size();
        int m = mat[0].size();
        int x = koord.first, y = koord.second;

        if (x == n - 1 || y == m - 1) return true;
        visited[x][y] = true;

        for (auto &p : adj[x][y]) {
            int nx = p.first, ny = p.second;
            if (!visited[nx][ny] && mat[x][y] >= mat[nx][ny]) {
                if (yedekdfs2(mat, adj, {nx, ny}, visited)) return true;
            }
        }
        return false;
    }

    int asildfs(vector<vector<int>> &mat, vector<vector<vector<pair<int, int>>>> &adj) {
        int n = mat.size();
        int m = mat[0].size();
        int sayac = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vector<vector<bool>> visited1(n, vector<bool>(m, false));
                vector<vector<bool>> visited2(n, vector<bool>(m, false));
                if (yedekdfs(mat, adj, {i, j}, visited1) && yedekdfs2(mat, adj, {i, j}, visited2))
                    sayac++;
            }
        }
        return sayac;
    }

    int countCoordinates(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<vector<pair<int, int>>>> adj(n, vector<vector<pair<int, int>>>(m));

        adj = kenarliAdj(adj, mat);
        return asildfs(mat, adj);
    }
};

// İkinci Çözüm: Verimlilik olarak iyi ve dfs mantığını özümsemek açısından önemli

class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    void dfs(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y) {
        int n = mat.size();
        int m = mat[0].size();
        visited[x][y] = true;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !visited[nx][ny] && mat[nx][ny] >= mat[x][y]) {
                dfs(mat, visited, nx, ny);
            }
        }
    }

    int countCoordinates(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
      
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
      
        for (int i = 0; i < n; i++) dfs(mat, pacific, i, 0);
        for (int j = 0; j < m; j++) dfs(mat, pacific, 0, j);
        for (int i = 0; i < n; i++) dfs(mat, atlantic, i, m - 1);
        for (int j = 0; j < m; j++) dfs(mat, atlantic, n - 1, j);
      
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) count++;
            }
        }
        return count;
    }
};
