class Solution {
public:
    int rev(int n){
        int r = 0;
        while(n > 0){
            r = r * 10 + (n % 10);
            n /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,long long> m;
        long long count = 0;
        int mod = 1e9 + 7;

        for(int x : nums){
            int diff = x - rev(x);
            count = (count + m[diff]) % mod;
            m[diff]++;
        }

        return count;
    }
};