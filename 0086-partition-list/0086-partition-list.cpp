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
    ListNode* partition(ListNode* head, int x) {
      if(head == nullptr || head->next == nullptr){
        return head;
      }
        vector<int> v;
        ListNode* curr = head;
        while(curr != nullptr){
            if(curr->val < x)
            v.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr != nullptr){
            if(curr->val >= x)
            v.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        int index = 0;
        while(curr != nullptr){
            curr->val = v[index++];
            curr = curr->next;
        }
        return head;
    }
};