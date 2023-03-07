class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0, high = totalTrips * (long long) time[0], ans = high;

        while(low < high){
            long long mid = low + (high - low)/2;
            long long count = 0;

            for(int i=0; i<time.size(); i++){
                count += mid/time[i];
            }

            if(count >= totalTrips){
                ans = min(ans, mid);
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
