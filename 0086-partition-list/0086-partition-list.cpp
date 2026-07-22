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
      ListNode* curr = head;
       ListNode* SmallerNode = new ListNode(0);
       ListNode* SmallNode = SmallerNode;
       ListNode* LargerNode = new ListNode(0);
       ListNode* LargeNode = LargerNode;
       while(curr != nullptr){
        if(curr->val < x){
            SmallNode->next = curr;
            SmallNode = SmallNode->next;
        }
        else{
            LargeNode->next = curr;
            LargeNode = LargeNode->next;
        }
        curr = curr->next;
       }
       LargeNode->next = nullptr;
       SmallNode->next = LargerNode->next;
       return SmallerNode->next;
    }
};