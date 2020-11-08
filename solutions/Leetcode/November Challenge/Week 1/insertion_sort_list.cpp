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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        ListNode* sorted = nullptr;
        while (cur) {
            // list is empty
            if (!sorted) {
                sorted = new ListNode(cur->val, nullptr);
            }
            else {
                
                ListNode* cur_sorted = sorted;
                ListNode* prev_sorted = nullptr;
                ListNode* new_sorted = nullptr;
                
                while (cur_sorted and cur_sorted->val < cur->val) {
                    prev_sorted = cur_sorted;
                    cur_sorted = cur_sorted->next;
                }
                
                new_sorted = new ListNode(cur->val, nullptr);
                
                // insertion before head
                if (!prev_sorted) {
                    new_sorted->next = sorted;
                    sorted = new_sorted;
                }
                else {
                    new_sorted->next = cur_sorted;
                    prev_sorted->next = new_sorted;
                }
            }
            cur = cur->next;
        }
        
        return sorted;
    }
};
