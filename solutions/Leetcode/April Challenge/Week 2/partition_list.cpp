// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// 
// You should preserve the original relative order of the nodes in each of the two partitions.

// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]

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
        if (!head) {
            return head;
        }
        vector<ListNode*> v;
        vector<ListNode*> v2;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur) {
            if (cur->val < x) {
                v.push_back(cur);
            }
            else {
                v2.push_back(cur);
            }
            prev = cur;
            cur = cur->next;
        }
        int N = v.size();
        for (int i = 0; i + 1 < N; i++) {
            v[i]->next = v[i + 1];
        }
        N = v2.size();
        for (int i = 0; i + 1 < N; i++) {
            v2[i]->next = v2[i + 1];
        }
        if (!v.empty()) {
            head = v.front();
            if (!v2.empty()) v.back()->next = v2.front();
        }
        else {
            if (!v2.empty()) head = v2.front();
        }
        if (!v2.empty()) {
            v2.back()->next = nullptr;
        }
        return head;
    }
};
