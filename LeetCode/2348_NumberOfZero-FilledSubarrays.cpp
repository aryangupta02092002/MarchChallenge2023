class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long count = 0, zeros = 0;
        for(int n : nums){
            if(n == 0){
                count += ++zeros;
            }
            else{
                zeros = 0;
            }
        }
        return count;
    }
};
