class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int MaxSum = nums[0];
        int CurrentSum = 0;
        for(int i = 0 ; i < n ; i++ ){
         CurrentSum +=nums[i];
         MaxSum = max(MaxSum,CurrentSum);
         if(CurrentSum < 0)
         CurrentSum = 0;
        }
        return MaxSum;
    }
    
};