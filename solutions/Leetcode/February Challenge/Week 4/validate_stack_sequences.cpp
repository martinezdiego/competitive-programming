class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        int N = pushed.size();
        int M = popped.size();
        if (N == 0 and M == 0) return true;
        while (i < N and j < M)
        {
            if (pushed[i] != popped[j]) 
                i++;
            else {
                pushed[i] = -1;
                j++;
                while (i >= 1 and pushed[i] == -1) i--;
            }
        }
        if (i == N) i--;
        while (i >= 0 and j < M)
        {
            if (pushed[i] == popped[j]) j++;
            i--;
        }
        while (i >= 0) {
            if (pushed[i] >= 0) return false;
            i--;
        }
        return i == -1 and j == M;
    }
}; 
