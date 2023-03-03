//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int findGCD(long long int a, long long int b){
        if(b == 0){
            return a;
        }
        return findGCD(b, a%b);
    }
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        // code here
        vector<long long int> ans;
        long long int gcd = findGCD(L, B);
        
        ans.push_back(L/gcd * B/gcd);
        ans.push_back(gcd);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends
