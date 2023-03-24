class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n), back(n);
        for(int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            back[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> vis(n, 0);
        vis[0] = 1;
        int ans = 0;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int tmp = q.front();    q.pop();
            vis[tmp] = 1;

            for(int i : adj[tmp]){
                if(!vis[i]){
                    ans++;
                    q.push(i);
                }
            }

            for(int i : back[tmp]){
                if(!vis[i]){
                    q.push(i);
                }
            }

        }
        return ans;
    }
};
