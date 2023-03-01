class Solution {
public:
    vector<int> mergeSort(vector<int> &nums){
        if(nums.size() == 1){
            return nums;
        }
        int div = nums.size()/2;
        vector<int> m1, m2;

        for(int i=0; i<div; i++){
            m1.push_back(nums[i]);
        }
        for(int i=div; i<nums.size(); i++){
            m2.push_back(nums[i]);
        }

        m1 = mergeSort(m1);
        m2 = mergeSort(m2);
        int ptr1 = 0, ptr2 = 0, ptr3 = 0;

        while(ptr3 < nums.size()){
            if(ptr1 == m1.size()){
                nums[ptr3] = m2[ptr2];
                ptr2++;
                ptr3++;
                continue;
            }

            if(ptr2 == m2.size()){
                nums[ptr3] = m1[ptr1];
                ptr1++;
                ptr3++;
                continue;
            }

            if(m1[ptr1] < m2[ptr2]){
                nums[ptr3] = m1[ptr1];
                ptr1++;
                ptr3++;
            }
            else{
                nums[ptr3] = m2[ptr2];
                ptr2++;
                ptr3++;
            }
        }
        return nums;
    }
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums);
    }
};
