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
        ListNode* start = head;
        head = new ListNode(0, head);
        ListNode* prev = head;
        while (start) 
        {
            if (start->next and start->val == start->next->val) {
                while (start->next and start->val == start->next->val) {
                    start = start->next;
                }
                prev->next = start->next;   
            }
            else {
                prev = prev->next;
            }
            start = start->next;
        }
        return head->next;
    }
};
