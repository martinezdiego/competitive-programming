class Solution {
private:
    double dist(vector<int>& p1, vector<int>& p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]); 
        }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = { p1, p2, p3, p4 };
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 4; l++) {
                        if (i == j) continue;
                        if (i == k) continue;
                        if (i == l) continue;
                        if (j == k) continue;
                        if (j == l) continue;
                        if (k == l) continue;
                        
                        double d12 = dist(points[i], points[j]);
                        double d13 = dist(points[i], points[k]);
                        double d14 = dist(points[i], points[l]);
                        double d23 = dist(points[j], points[k]);
                        double d24 = dist(points[j], points[l]);
                        double d34 = dist(points[k], points[l]);
                        double d41 = dist(points[l], points[i]);
                        
                        if (d12 == 0 || d13 == 0 || d14 == 0) return false;
                        
                        bool ok = d12 > 0 && d12 == d23 && d23 == d34 && d34 == d41 && d13 == d24;
                        
                        if (ok) return true;
                    }                    
                }
            }
        }
        return false;
    }
};
