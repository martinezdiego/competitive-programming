class Solution {
private:
    void count_sort(vector<int> & v)
    {
        vector<int> cubets(100005, 0);
        vector<int> neg;
        vector<int> pos;
        int N = v.size();
        
        for (int i = 0; i < N; i++) {
            if (v[i] < 0) {
                cubets[-v[i]]++;
            }
        }
        
        for (int i = cubets.size() - 1; i >= 0; i--) {
            while (cubets[i]--) neg.push_back(-i);
        }
        
        cubets.assign(100005, 0);
        
        for (int i = 0; i < N; i++) {
            if (v[i] >= 0) {
                cubets[v[i]]++;
            }
        }
        
        for (int i = 0; i < cubets.size(); i++) {
            while (cubets[i]--) pos.push_back(i);
        }
        
        // for (int i : neg) cout << i << ' ';
        // cout << endl;
        // for (int i : pos) cout << i << ' ';
        // cout << endl;
        
        int idx = 0;
        for (int val : neg) v[idx++] = val;
        for (int val : pos) v[idx++] = val;
        
    }
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v = nums;
        //sort(v.begin(), v.end());
        count_sort(v);
        int N = nums.size();
        int first = -1;
        int last = -1;
        for (int i = 0; i < N; i++) {
            if (nums[i] != v[i]) {
                if (first == -1) first = i;
                else last = i;
            }
        }
        if (first == -1) {
            return 0;
        }
        if (last == -1) last = first;
        return last - first + 1;
    }
}; 
