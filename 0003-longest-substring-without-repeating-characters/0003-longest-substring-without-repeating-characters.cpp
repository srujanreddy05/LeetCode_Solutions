class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int left = 0,maxlen = 0;
        for(int right = 0 ; right < s.size();right++){
        map[s[right]]++;
        while(map[s[right]] > 1){
            map[s[left]]--;
            left++;
        }
        maxlen = max(maxlen,right - left + 1);
        }
        return maxlen;
    }
};