class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int count=0;
        int sz = piles.size();
        int left=1, right = *max_element(piles.begin(), piles.end());
        while(left < right){
            int mid = (left + right)/2;
            int curr=0;
            
            for(int pile : piles){
                curr += pile/mid + (pile%mid != 0);
            }
            if(curr <= h){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return right;
    }
};
