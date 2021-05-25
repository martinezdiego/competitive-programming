// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
// 
// We repeatedly make k duplicate removals on s until we no longer can.
// 
// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
// 
// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        for (char c : s) {
            if (st.empty() or st.back().first != c) {
                st.push_back({c, 1});
            }
            else {
                st.back().second++;
                if (st.back().second == k) {
                    st.pop_back();
                }
            }
        }
        string ans;
        for (pair<char, int> & p : st) {
            ans.append(string(p.second, p.first));
        }
        return ans;
    }
}; 
