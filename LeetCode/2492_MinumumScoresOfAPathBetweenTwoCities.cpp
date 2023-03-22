class Solution {
public:
    set<int> s;
    int mn = INT_MAX;
    void dfs(int idx, vector<vector<int>> &adj, vector<int> &vis){
        if(vis[idx] == 1){
            return;
        }
        vis[idx] = 1;
        for(auto x : adj[idx]){
            if(vis[x] == 0){
                s.insert(x);
                dfs(x, adj, vis);
            }
        }
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n+1);
        map<pair<int, int>, int> m;

        for(auto x : roads){
            m[{min(x[0], x[1]), max(x[0], x[1])}] = x[2];
        }

        for(auto i : roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n+1, 0);
        dfs(1, adj, vis);
        for (auto y : m)
        {
            if(s.find(y.first.first)!=s.end() || s.find(y.first.second)!=s.end()){
                mn=min(mn,y.second);
            }
        }
        return mn;
    }
};
