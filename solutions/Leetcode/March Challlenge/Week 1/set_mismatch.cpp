class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        N = N*(N+1)/2;
        set<int> s;
        int repeated = 0;
        for (int i : nums) {
            if(s.insert(i).second == false) {
                repeated = i;   
            }
        }
        for (int i : s) N -= i;
        return {repeated, N};
    }
};
