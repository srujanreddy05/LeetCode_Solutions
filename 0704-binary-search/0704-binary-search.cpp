class Solution {
public:
    int search(vector<int>& nums, int target) {
    return BinarySearch(nums,0,nums.size() - 1, target);
    }
    int BinarySearch(vector<int>& nums,int left, int right, int target){
        if(left > right){
            return -1;
        }
        int mid = left + (right - left) / 2;
        if(nums[mid]==target){
                return mid;
            }
            if(nums[mid] < target){
                return BinarySearch(nums,mid + 1,right,target);
            }
            else{
                return BinarySearch(nums,left,mid - 1,target);
            }
    }
  
};