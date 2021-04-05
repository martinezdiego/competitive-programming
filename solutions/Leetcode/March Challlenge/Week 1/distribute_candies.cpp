class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int N = candyType.size();
        set<int> s;
        for (int candy : candyType) s.insert(candy);
        int cnt = s.size();
        return min(N/2, cnt);
    }
};
