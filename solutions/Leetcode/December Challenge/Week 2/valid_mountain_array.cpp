 
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int N = arr.size();
        if (N < 3) return false;
        
        int end = 0;
        bool ans = false;
        
        if (end + 1 < N and arr[end] < arr[end + 1]) {
            while (end + 1 < N and arr[end] < arr[end + 1]) end++;
            if (end + 1 < N and arr[end] > arr[end + 1]) {
                while (end + 1 < N and arr[end] > arr[end + 1]) end++;
                return end == N-1;
            }
        }
        
        return false;
    }
};
