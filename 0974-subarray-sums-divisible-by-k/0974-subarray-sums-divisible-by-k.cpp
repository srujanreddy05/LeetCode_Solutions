class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int n = nums.size();
      int count = 0;
      unordered_map<int,int>map;
      map[0]=1;
      int sum = 0;
      for(int num : nums){
        sum += num;
        int rem = sum%k;
         if(rem<0) rem+=k;
       if(map.count(rem))
       count+=map[rem];
       map[rem]++;
      }
      return count;  
    }
};