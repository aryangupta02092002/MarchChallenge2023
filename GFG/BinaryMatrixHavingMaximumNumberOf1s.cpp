//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    //TC : O(N*N)
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int mx1s = 0, idx = 0;
        for(int i=0; i<N; i++){
            int count = 0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            if(count > mx1s){
                mx1s = count;
                idx = i;
            }
        }
        return {idx, mx1s};
        
    }
  
  //TC: O(N)
  vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int i = 0, j = N-1;
        int row = 0, mx1s = 0;
        
        while(i < N && j >= 0){
            if(mat[i][j]){
                row = i;
            }
            while(j >= 0 && mat[i][j]){
                j--;
            }
            mx1s = N-j-1;
            i++;
        }
        return {row, mx1s};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends
