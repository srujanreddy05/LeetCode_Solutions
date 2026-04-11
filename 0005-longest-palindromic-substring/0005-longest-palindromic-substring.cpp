class Solution {
public:
    string longestPalindrome(string s) {
     int n = s.size();
     int start = 0,end = 0;
     for(int i = 0; i < n ; i++){
        int odd_length = expand(s,i,i);
        int even_length = expand(s,i,i+1);
        int len = max(odd_length,even_length);
        if(len > (end - start)){
            start = i - (len - 1)/2;
            end = i + len/2;
        }
     }
     return s.substr(start,end - start + 1);  
    }
    int expand(string s, int left , int right){
        while(left >=0 && s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
};