// Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        vector<ListNode*> v;
        while (cur) {
            v.push_back(cur);
            prev = cur;
            cur = cur->next;            
        }
        int N = v.size();
        if (n > N) return head;
        if (n == N) return head->next;
        v[N - n - 1]->next = v[N - n]->next;
        return head;
    }
};
