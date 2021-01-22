class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> ans;
        multiset<int> s;
        int cnt = 0;
        int start = 0;
        for (int i = 0; i < N; i++)
        {
            cnt++;
            s.insert(nums[i]);
            if (cnt > k) {
                auto pos = s.find(nums[start]);
                s.erase(pos);
                start++;
                cnt--;
            }
            if (cnt == k) {
                int mx = *(--s.end());
                ans.push_back(mx);
            }
        }
        return ans;
    }
};
