//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        int ans=leaves;
        vector<int> v(leaves+1, 0);
        for(int i=0; i<N; i++){
            int val=frogs[i];
           
            if(val<=leaves and v[val]==0){
                while(val<=leaves){
                    if(v[val]==0)
                        ans--;
               
                    v[val]++;
                    val+=frogs[i];
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
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends
