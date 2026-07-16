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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 1){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while(true){
            ListNode* kth = prevGroup;
            for(int i = 0; i < k && kth != nullptr;i++){
                kth = kth->next;
            }
            if(kth == nullptr) break;

            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            while(curr != groupNext){
                ListNode* Next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = Next; 
            }
            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
        }
        return dummy->next;
    }
};