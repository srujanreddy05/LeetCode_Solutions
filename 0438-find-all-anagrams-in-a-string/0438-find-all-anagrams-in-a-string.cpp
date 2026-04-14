class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.size() > s.size()) return result;
        vector<int> pFreq(26, 0), windowFreq(26, 0);
        for (int i = 0; i < p.size(); i++) {
            pFreq[p[i] - 'a']++;
            windowFreq[s[i] - 'a']++;
        }
        if (pFreq == windowFreq) result.push_back(0);
        for (int i = p.size(); i < s.size(); i++) {
            windowFreq[s[i] - 'a']++;                       
            windowFreq[s[i - p.size()] - 'a']--;            
            if (pFreq == windowFreq)
                result.push_back(i - p.size() + 1);
        }
        return result;
    }
};