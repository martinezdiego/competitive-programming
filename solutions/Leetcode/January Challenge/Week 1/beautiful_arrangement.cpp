class Solution {
private:
    int ans;
    void permute(vector<int> & perm, int l)
    {
        if (l == perm.size()) {
            ans++;
            return;
        }
        for (int i = l; i < perm.size(); i++) {
            swap(perm[i], perm[l]);
            if (perm[l]%(l + 1) == 0 or (l + 1)%perm[l] == 0)
                permute(perm, l + 1);
            swap(perm[i], perm[l]);
        }
    }
public:
    int countArrangement(int n) {
        vector<int> perm;
        for (int i = 1; i <= n; i++) perm.push_back(i);
        ans = 0;
        permute(perm, 0);
        return ans;
    }
};
