/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* skipA = headA;
        ListNode* skipB = headB;

        while(skipA != NULL){
            lenA++;
            skipA = skipA->next;
        }

        while(skipB != NULL){
            lenB++;
            skipB = skipB->next;
        }

        skipA = headA;
        skipB = headB;

        while(lenA > lenB){
            skipA = skipA->next;
            lenA--;
        }

        while(lenB > lenA){
            skipB = skipB->next;
            lenB--;
        }

        while(skipA != skipB){
            skipA = skipA->next;
            skipB = skipB->next;
        }

        return skipA;
    }
};