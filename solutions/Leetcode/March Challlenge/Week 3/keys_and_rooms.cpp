// There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 
// 
// Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.
// 
// Initially, all the rooms start locked (except for room 0). 
// 
// You can walk back and forth between rooms freely.
// 
// Return true if and only if you can enter every room.

// Input: [[1],[2],[3],[]]
// Output: true
// Explanation:  
// We start in room 0, and pick up key 1.
// We then go to room 1, and pick up key 2.
// We then go to room 2, and pick up key 3.
// We then go to room 3.  Since we were able to go to every room, we return true.

class Solution {
private:
    void dfs(int n, vector<vector<int>>& rooms, vector<bool> & visited)
    {
        if (visited[n]) return;
        visited[n] = true;
        for (int key : rooms[n])
            dfs(key, rooms, visited);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        if (N == 1 and rooms[0].empty()) return true;
        vector<bool> visited(N, 0);
        for (int key : rooms[0])
        {
            // visited.assign(N, 0);
            visited[0] = true;
            dfs(key, rooms, visited);
            bool ok = true;
            for (int i = 0; i  < N; i++) {
                ok &= visited[i];
            }
            if (ok) return true;
        }
        return false;
    }
}; 
