class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int time = 1;
        vector<int> vis(edges.size());

        for(int i=0; i<edges.size(); ++i){
            if(vis[i]){
                continue;
            }
            const int start = time;
            int u = i;

            while(u != -1 && !vis[u]){
                vis[u] = time++;
                u = edges[u];
            }

            if(u != -1 && vis[u] >= start){
                ans = max(ans, time - vis[u]);
            }
        }
        return ans;
    }
};
