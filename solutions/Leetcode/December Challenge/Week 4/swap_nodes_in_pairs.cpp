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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur) {
            if (cur->next) {
                ListNode* tmp = cur->next->next;
                if (!prev) {
                    head = cur->next;
                    head->next = cur;
                    cur->next = tmp;
                }
                else {
                    prev->next = cur->next;
                    cur->next->next = cur;
                    cur->next = tmp;
                }
                prev = cur;
                cur = cur->next;
            }
            else
                break;
        }
        return head;
    }
};
