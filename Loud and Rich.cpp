class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> adj(quiet.size());
        for(auto kenar : richer){
            adj[kenar[1]].push_back(kenar[0]);
        }
        vector<int> answer(quiet.size(), -1);
        for(int w = 0; w < quiet.size(); ++w){
            stack<int> derin;
            vector<bool> visited(quiet.size(), false);
            derin.push(w);
            visited[w] = true;
            int min = w;
            while(!derin.empty()){
            int uc = derin.top();
            derin.pop();
                for(int gez : adj[uc]){
                    if(visited[gez] != true){
                        derin.push(gez);
                        visited[gez] = true;
                    if(quiet[gez] < quiet[min]) min = gez;
                }
                    }
            }
            answer[w] = min;
        }
        return answer;
    }
};
//stack ile dfs gerçekleştirmek yerine doğrudan recursive yapıp zamandan tasarruf edilebilir.
