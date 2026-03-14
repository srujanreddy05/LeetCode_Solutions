class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Prefix = 1;
        int Suffix = 1;
        int n = nums.size();
        int MaxProd = INT_MIN;

        for(int i = 0; i < n; i++){
            if(Prefix == 0) Prefix = 1;
            if(Suffix == 0) Suffix = 1;

            Prefix *= nums[i];
            Suffix *= nums[n - 1 - i];

            MaxProd = max(MaxProd, max(Prefix, Suffix));
        }

        return MaxProd;
    }
};