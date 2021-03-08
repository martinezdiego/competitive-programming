/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        Node* prev = nullptr;
        Node* newHead = nullptr;
        Node* newCur = nullptr;
        Node* newPrev = nullptr;
        int idx = 0;
        map<Node*, int> nodes;
        vector<Node*> newNodes;
        while (cur) {
            if (!newHead) {
                newHead = new Node(cur->val);
                newCur = newHead;
            }
            else if (!newCur) {
                newCur = new Node(cur->val);
                newPrev->next = newCur;            
            }
            nodes[cur] = idx++;
            newNodes.push_back(newCur);
            newPrev = newCur;
            newCur = newCur->next;
            cur = cur->next;
        }
        cur = head;
        newCur = newHead;
        while (cur) {
            if (cur->random) {
                int randomIdx = nodes[cur->random];
                newCur->random = newNodes[randomIdx];
            }
            cur = cur->next;
            newCur = newCur->next;
        }
        return newHead;
    }
};
