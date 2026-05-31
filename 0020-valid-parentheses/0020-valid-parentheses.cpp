class Solution {
public:
    bool isValid(string s) {
      stack <int> st;
      unordered_map <char,char> map = {
        {')','('},
        {'}','{'},
        {'[]','['},

      };
      for (char ch : s){
        if(map.count(ch)){
            if(st.empty() || st.top() != map[ch]){
                return false;
            }
            st.pop();
        }
        else {
            st.push(ch);
        }
      } 
      return st.empty();
    }
};