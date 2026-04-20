class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tmap;
        for(char c : t) tmap[c]++;
        unordered_map<char,int> smap;
        int left = 0, count = t.size();
        int minlen = INT_MAX;
        int start = 0;
        for (int right = 0; right < s.size(); right++){
            char ch = s[right];
            smap[ch]++;
            if(tmap.count(ch) && smap[ch] <= tmap[ch]){
                count--;
            }
            while(count == 0){
                if(right - left + 1 < minlen){
                    minlen = right - left + 1;
                    start = left;
                }
                char leftChar = s[left];
                smap[leftChar]--;
                if(tmap.count(leftChar) && smap[leftChar] < tmap[leftChar]){
                    count++;
                }
                left++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};