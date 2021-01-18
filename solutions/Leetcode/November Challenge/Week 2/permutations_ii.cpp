class Solution {
private:
    map<int,int> freq;
    vector<vector<int>> ans;

    void backtrack(vector<int> & comb, int length) {
        if (comb.size() == length) {
            ans.push_back(comb);
            return;
        }

        for (pair<int,int> entry: freq) {
            int key = entry.first;
            int value = entry.second;
            
            if (value == 0) continue;

            comb.push_back(key);
            freq[key]--;

            backtrack(comb, length);

            comb.pop_back();
            freq[key] = value;
        }
    }
        
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> comb;
        for (int value : nums) {
            freq[value]++;
        }
        backtrack(comb, nums.size());
        return ans;
    }
};
