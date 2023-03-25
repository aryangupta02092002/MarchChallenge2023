class Solution {
public:
    void dfs(vector<int> adj[], int src, vector<bool> &vis, int &count){
        if(vis[src]){
            return;
        }
        vis[src] = true;
        count++;
        for(auto e : adj[src]){
            if(!vis[e]){
                dfs(adj, e, vis, count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long ans = 0;
        vector<bool> vis(n, false);
        vector<int> tmp;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                int count = 0;
                dfs(adj, i, vis, count);
                tmp.push_back(count);
            }
        }

        int total = 0;
        for(int i=0; i<tmp.size(); i++){
            ans += (long)((long) tmp[i] * (long)(n-total-tmp[i]));
            total += tmp[i];
        }
        return ans;
    }
};
