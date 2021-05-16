 
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
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        int N = 0;
        vector<int> nodes;
        while (cur) {
            nodes.push_back(cur->val);
            cur = cur->next;
        }
        N = nodes.size();
        N = (N+1)/2;
        int l = 0;
        int r = nodes.size() - 1;
        for (int i = 0; i < N; i++) {
            if (nodes[l++] != nodes[r--]) return false;
        }
        return true;
    }
};
