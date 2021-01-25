class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == N - 1 || flowerbed[i + 1] == 0)) 
                flowerbed[i] = 1, cnt++;
            if (cnt >= n) return true;
        }
        return false;
    }
}; 
