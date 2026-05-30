class Solution {
public:
    int minLength(string s) {
        string result = "";
        for(char ch : s){
            if(!result.empty()){
                char last = result.back();
                if((last == 'A' && ch == 'B') || last == 'C' && ch == 'D'){
                    result.pop_back();
                    continue;
                }
            }
           result.push_back(ch);
        }
        return result.size();
    }
};