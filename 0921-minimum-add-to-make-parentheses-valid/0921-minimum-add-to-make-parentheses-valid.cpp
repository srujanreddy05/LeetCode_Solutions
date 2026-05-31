class Solution {
public:
    int minAddToMakeValid(string s) {
        int openNeeded = 0; 
        int openCount = 0;   
        for (char ch : s) {
            if (ch == '(') {
                openCount++;
            } else {
                if (openCount > 0) {
                    openCount--;  
                } else {
                    openNeeded++;  
                }
            }
        }
        
        return openNeeded + openCount;
    }
};