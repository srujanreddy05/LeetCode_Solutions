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
        ListNode* tempA = headA;
        ListNode* tempB = headB;
       int LenA = 0;
       while(tempA!=NULL){
       LenA++;
       tempA = tempA->next;
       }
       int LenB =0;
       while(tempB!=NULL){
        LenB++;
        tempB = tempB->next;
       }
      tempA = headA;
      tempB = headB;
      if(LenA>LenB){
        int diff = LenA-LenB;
        for(int i = 1;i <=diff;i++){
            tempA = tempA->next;
        }
        while(tempA!=tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
      }
      else{
        int diff = LenB-LenA;
        for(int i = 1;i <=diff;i++){
            tempB = tempB->next;
        }
        while(tempA!=tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempB;
      }
      return NULL;
    }
};