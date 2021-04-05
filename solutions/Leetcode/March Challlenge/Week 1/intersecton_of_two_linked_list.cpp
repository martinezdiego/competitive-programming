/*
 Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getListLen(ListNode* head)
    {
        int len = 0;
        ListNode* cur = head;
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int N = getListLen(headA);
        int M = getListLen(headB);
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (N > M) {
            curA = curA->next;
            N--;
        }
        while (M > N) {
            curB = curB->next;
            M--;
        }
        while (curA)
        {
            if (curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};
