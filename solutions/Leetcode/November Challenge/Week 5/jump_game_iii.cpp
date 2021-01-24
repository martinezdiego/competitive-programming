class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int N = arr.size();
        queue<int> q;
        q.push(start);
        
        while (not q.empty())
        {
            int cur = q.front();
            q.pop();
            
            if (arr[cur] == 0) return true;
            
            int a = cur + arr[cur];
            int b = cur - arr[cur];
            
            arr[cur] = -1;
            
            if (a < N and arr[a] != -1) q.push(a);
            if (b >= 0 and arr[b] != -1) q.push(b);
        }
        return false;
    }
};
