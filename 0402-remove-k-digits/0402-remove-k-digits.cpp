class Solution {
public:
    string removeKdigits(string num, int k) {
        string sb;
        for (char ch : num){
            while ( k > 0 && !sb.empty() && sb.back() > ch){
                sb.pop_back();
                k--;
            }
            sb.push_back(ch);
        }
        sb.resize(sb.size() - k);
        int start = 0;
        while( start < sb.size() && sb[start]=='0'){
            start++;
        }
        string ans = sb.substr(start);
        return ans.empty() ? "0" : ans;
    }
};