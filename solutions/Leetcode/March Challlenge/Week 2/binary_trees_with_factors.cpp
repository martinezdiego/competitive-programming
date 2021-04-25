class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        unordered_map<int, long long> fmap;
        for (int num : arr)
        {
            long long ways = 1;
            int limit = sqrt(num);
            for (int i = 0, fA = arr[0]; fA <= limit; fA = arr[++i])
            {
                if (num%fA != 0) continue;
                int fB = num/fA;
                if (fmap.find(fB) != fmap.end()) {
                    ways += (fmap[fA]%1000000007 * fmap[fB]%1000000007 * (fA == fB ? 1 : 2))%1000000007;
                }
            }
            fmap[num] = ways;
            ans = (ans%1000000007 + ways%1000000007)%1000000007;
        }
        return ans;
    }
};
