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
    private:
        deque<ListNode*> getNodes(ListNode* list) {
            deque<ListNode*> nodes;
            ListNode* prev;
            ListNode* cur;
            cur = list;
            while (cur) {
                nodes.push_back(cur);
                cur = cur->next;
            }
            return nodes;
        }
    
        ListNode* toList(const deque<int> & nodes) {
            ListNode* head = new ListNode(nodes[0]);
            ListNode* cur = head;
            ListNode* prev;
            for (int i = 1; i < nodes.size(); i++) {
                prev = cur;
                cur = new ListNode(nodes[i]);
                prev->next = cur;
                
            }
            return head;
        }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        deque<ListNode*> l1_nodes = getNodes(l1);
        deque<ListNode*> l2_nodes = getNodes(l2);
        deque<int> ans;
        
        int l1_size = l1_nodes.size();
        int l2_size = l2_nodes.size();
        int carry = 0;
        
        if (min(l1_size, l2_size) == l1_size) {
            for (int i = l1_size; i < l2_size; i++) {
                l1_nodes.push_front(new ListNode(0));
            }
            l1_size = l1_nodes.size();
        }
        else {
            for (int i = l2_size; i < l1_size; i++) {
                l2_nodes.push_front(new ListNode(0));
            }
            l2_size = l2_nodes.size();
        }
        
        assert(l1_size == l2_size);
        
        for (int i = 0; i < max(l1_size, l2_size); i++) {
            int l1_node_val = l1_nodes[l1_size - i - 1]->val;
            int l2_node_val = l2_nodes[l2_size - i - 1]->val;
            int sum =  l1_node_val + l2_node_val;
            sum += carry;
            carry = 0;
            if (sum > 9) {
                carry = (sum/10)%10;
            }
            ans.push_front(sum%10);
        }
        
        if (carry) {
            ans.push_front(carry);
        }
        
        return toList(ans);
    }
};
