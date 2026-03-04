class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     int n = nums.size();
     vector<int> result(n-k+1);
     deque<int> deque;
     for(int right = 0; right < n;right++){
        while(!deque.empty()&& deque.front()<= right - k){
       deque.pop_front();     
        }
        while(!deque.empty() && nums[deque.back()] < nums[right]){
    deque.pop_back();
        }
        deque.push_back(right);
        if(right >= k-1 ){
            result[right-k+1]=nums[deque.front()];
        }
     } 
     return result;  
    }
};