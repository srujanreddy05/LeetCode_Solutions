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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector <int> v1;
        vector<int> v2;
        while(l1 != nullptr){
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        vector<int> ans ;
        int i = 0;
        int j = 0;
        int carry = 0;
        while(i < v1.size() || j < v2.size() || carry != 0){
            int sum = carry;
            if(i < v1.size())
            sum += v1[i++];
            if(j < v2.size())
            sum += v2[j++];
            ans.push_back(sum % 10);
            carry = sum / 10;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for(int digit : ans){
            curr->next = new ListNode(digit);
            curr = curr->next;
        }
        return dummy->next;
    }
};