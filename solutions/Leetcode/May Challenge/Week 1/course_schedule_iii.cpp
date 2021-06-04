// There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.
// 
// You will start on the 1st day and you cannot take two or more courses simultaneously.
// 
// Return the maximum number of courses that you can take.
// 
// Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
// Output: 3

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int currentTotalTime = 0;
        int ans = 0;
        for (vector<int> & course : courses) {
            if (currentTotalTime + course[0] <= course[1]) {
                currentTotalTime += course[0];
                pq.push(course[0]);
            }
            else if (!pq.empty() and pq.top() > course[0]) {
                currentTotalTime += course[0] - pq.top();
                pq.pop();
                pq.push(course[0]);
            }
        }
        ans = max(ans, (int)pq.size());
        return ans;
    }
};
