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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* startL1 = l1;
        ListNode* startL2 = l2;
        ListNode* mergedList = nullptr;
        ListNode* startMergedList = nullptr;
        while (startL1 and startL2)
        {
            if (startL1->val <= startL2->val) {
                if (!startMergedList) {
                    startMergedList = new ListNode(startL1->val);
                    mergedList = startMergedList;
                }
                else {
                    startMergedList->next = new ListNode(startL1->val);
                    startMergedList = startMergedList->next;
                }
                startL1 = startL1->next;
            }
            else {
                if (!startMergedList) {
                    startMergedList = new ListNode(startL2->val);
                    mergedList = startMergedList;
                }
                else {
                    startMergedList->next = new ListNode(startL2->val);
                    startMergedList = startMergedList->next;
                }
                startL2 = startL2->next;
            }
        }
        while (startL1) {
            if (!startMergedList) {
                    startMergedList = new ListNode(startL1->val);
                mergedList = startMergedList;
            }
            else {
                startMergedList->next = new ListNode(startL1->val);
                startMergedList = startMergedList->next;
            }
            startL1 = startL1->next;
        }
        while (startL2) {
            if (!startMergedList) {
                startMergedList = new ListNode(startL2->val);
                mergedList = startMergedList;
            }
            else {
                startMergedList->next = new ListNode(startL2->val);
                startMergedList = startMergedList->next;
            }
            startL2 = startL2->next;
        }
        return mergedList;
    }
};
