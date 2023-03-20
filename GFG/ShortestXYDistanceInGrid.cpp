//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        int ans = INT_MAX;
        vector<vector<int>> dp(N, vector<int> (M, INT_MAX - 10000));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(grid[i][j] == 'X'){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(i-1 >= 0){
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
                }
                if(j-1 >= 0){
                    dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
                }
                if(i+1<N){
                    dp[i][j] = min(dp[i+1][j]+1, dp[i][j]);
                }
                if(j+1<M){
                    dp[i][j] = min(dp[i][j+1]+1, dp[i][j]);
                }
                if(grid[i][j] == 'Y'){
                    ans = min(dp[i][j], ans);
                }
            }
        }
        
        for(int i=N-1; i>=0; i--){
            for(int j=M-1; j>=0; j--){
                if(i-1 >= 0){
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
                }
                if(j-1 >= 0){
                    dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
                }
                if(i+1<N){
                    dp[i][j] = min(dp[i+1][j]+1, dp[i][j]);
                }
                if(j+1<M){
                    dp[i][j] = min(dp[i][j+1]+1, dp[i][j]);
                }
                if(grid[i][j] == 'Y'){
                    ans = min(dp[i][j], ans);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
