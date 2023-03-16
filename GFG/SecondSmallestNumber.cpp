//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        if(D == 1 || S == 1 || S >= 9*D){
            return "-1";
        }
        bool isChange = 0;
        string s = "";
        for(int i=0; i<D; i++){
            int dig;
            if(S > 9){
                dig = 9;
                S -= 9;
            }
            else{
                if(i == D-1){
                    dig = S;
                }
                else{
                    if(S > 1){
                        dig = S-1;
                        S = 1;
                    }
                    else{
                        dig = 0;
                    }
                }
            }
            
            if(!isChange && dig<9 && s.size() > 0){
                dig++;
                char c = s[s.size()-1];
                s[s.size()-1] = --c;
                isChange = 1;
            }
            s += to_string(dig);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
