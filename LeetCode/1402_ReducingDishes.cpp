class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());

        vector<int> sum = satisfaction;

        for(int i=1; i<n; i++){
            sum[i] += sum[i-1];
        }
        int mx=0, curr=0;

        for(int i=0; i<n; i++){
            curr += sum[i];
            mx = max(curr, mx);
        }
        return mx;
    }
};
