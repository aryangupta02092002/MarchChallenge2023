//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        bool check(int n){
            return n%2 == 0;
        }
        
        vector<int> findRange(int idx, bool chk,vector<int> a){
            int end = idx;
            while(end<a.size() && check(a[end]) == chk)
                end++;
            return {idx, end};
        }
        
        void sortRange(vector<int>&a , int start, int end){
            sort(a.begin() + start, a.begin() + end, greater<>());
        }
        
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            int idx = 0;
            while(idx < n){
                vector<int> range = findRange(idx, check(a[idx]), a);
                sortRange(a, range[0], range[1]);
                idx = range[1];
            }
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
