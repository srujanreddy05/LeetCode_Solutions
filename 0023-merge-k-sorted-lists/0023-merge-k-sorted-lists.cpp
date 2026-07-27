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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;

        for (ListNode* head : lists) {
            while (head != nullptr) {
                nums.push_back(head->val);
                head = head->next;
            }
        }

        sort(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for (int num : nums) {
            curr->next = new ListNode(num);
            curr = curr->next;
        }

        return dummy->next;
    }
};