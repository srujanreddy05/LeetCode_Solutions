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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode* curr = head;
        ListNode* nextNode = head->next;
        
        while (nextNode != nullptr) {
            if (curr->val == nextNode->val) {
                curr->next = nextNode->next;
                nextNode = nextNode->next;
            } else {
                curr = curr->next;
                nextNode = nextNode->next;
            }
        }
        
        return head;
    }
};