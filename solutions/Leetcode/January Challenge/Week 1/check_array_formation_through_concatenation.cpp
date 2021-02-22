class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int N = arr.size();
        int M = pieces.size();
        int len = 0;
        bool valid = true;
        int i = 0;
        int match = 0;
        while (len < N and valid)
        {
            if (i == 0) {
                match = 0;
            }
            
            if (pieces[i][0] == arr[len]) {
                if (pieces[i].size() > 1 and pieces[i].size() > N - len) {
                    valid = false;
                    break;
                }
                for (int j = 0; j < pieces[i].size(); j++) {
                    if (pieces[i][j] == arr[len]) len++, match++;
                    else {
                        valid = false;
                        break;
                    }
                }
            }
            else if (i == M - 1 and !match) {
                valid = false;
            }
            
            i++;
            i %= M;
        }
        return len == N and valid;
    }
};
