// Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].
// 
// Return any permutation of A that maximizes its advantage with respect to B.

// Input: A = [2,7,11,15], B = [1,10,4,11]
// Output: [2,11,7,15]

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> sA;
        for (int cur : A) sA.insert(cur);
        int N = A.size();
        vector<int> ans(N);
        for (int i = 0; i < N; i++) {
            set<int>::iterator it = sA.upper_bound(B[i]);
            ans[i] = (it != sA.end() ? *it : -1);
            if (it != sA.end()) sA.erase(it);
        }
        int i = 0;
        for (int cur : sA) {
            while (ans[i] != -1) i++;
            ans[i] = cur;
        }
        return ans;
    }
}; 
