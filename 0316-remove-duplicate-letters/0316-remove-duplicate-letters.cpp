#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastOccurrence(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            lastOccurrence[s[i] - 'a'] = i;
        }

        string result;
        vector<bool> inResult(26, false);

        for (int i = 0; i < s.length(); ++i) {
            char current = s[i];
            
            if (inResult[current - 'a']) {
                continue;
            }

            while (!result.empty() && 
                   result.back() > current && 
                   lastOccurrence[result.back() - 'a'] > i) {
                inResult[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(current);
            inResult[current - 'a'] = true;
        }

        return result;
    }
};