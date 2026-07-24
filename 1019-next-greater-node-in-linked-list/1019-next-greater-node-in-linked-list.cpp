/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        ListNode* curr = head;
        while(curr != nullptr){
            int greater = 0;
            ListNode* temp = curr->next;

            while(temp != nullptr){
                if(temp->val > curr->val){
                    greater = temp->val;
                    break;
                }
                temp = temp->next;
            }
            v.push_back(greater);
            curr = curr->next;
        }
       vector<int> result(v.size());
        for(int i = 0; i < v.size(); i++)
        result[i] = v[i];
        return result;
    }
};