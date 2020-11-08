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
    int getDecimalValue(ListNode* head) {
        int pwr = -1;
        int ans = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            pwr++;
        }
        cur = head;
        while (cur) {
            int value = cur->val;
            if (value) ans += (int)pow(2, pwr);
            pwr--;
            cur = cur->next;
        }
        return ans;
    }
};
