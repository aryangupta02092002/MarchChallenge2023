//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    string delAB(char a,char b,long long& cnt,string& S){
        string temp;
        for(const auto& x: S){
            if(!temp.empty() && temp.back() == a && x == b){
                temp.pop_back();
                cnt++;
            }
            else temp += x;
        }
        return temp;
    }
    
    long long solve(int X,int Y,string S){
      //code here
        long long count1 = 0, count2 = 0;
        
        char a = 'p', b = 'r';
        if(X < Y)swap(a,b);
        
        string temp = delAB(a, b, count1, S);
        delAB(b, a, count2, temp);
        
        if(X < Y)
            swap(count1, count2);
        
        return count1*X + count2*Y;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
