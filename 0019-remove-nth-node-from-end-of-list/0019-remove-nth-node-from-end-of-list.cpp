class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;

        while(curr != NULL){
            len++;
            curr = curr->next;
        }

        if(n == len){
            return head->next;
        }

        int pos = len - n;
        curr = head;

        for(int i = 1; i < pos; i++){
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return head;
    }
};