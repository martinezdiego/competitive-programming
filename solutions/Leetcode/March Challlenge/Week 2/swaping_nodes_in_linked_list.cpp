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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> v;
        ListNode* cur = head;
        while (cur)  {
            v.push_back(cur);
            cur = cur->next;
        }
        int N = v.size();
        int l = k - 1;
        int r = N - k;
        swap(v[l], v[r]);
        if (l > 0) {
            v[l - 1]->next = v[l];
        }
        else {
            head = v[l];
        }
        
        if (l + 1 < N) {
            v[l]->next = v[l + 1];
        }
        else {
            v[l]->next = nullptr;    
        }
        
        if (r > 0) {
            v[r - 1]->next = v[r];
        }
        else {
            head = v[r];
        }
        
        if (r + 1 < N) {
            v[r]->next = v[r + 1];
        }
        else {
            v[r]->next = nullptr;
        }
        
        return head;
    }
};
