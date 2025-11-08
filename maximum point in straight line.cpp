/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane,
 return the maximum number of points that lie on the same straight line.*/ 

 /********************************** approach 1 ****************************************** */ 
  /* the intution is that we will make the slope and get the slope of two points  if they get the same add it to theslope value ,
     if slope is 0 means that the point  is same  dx dy anddx1 dy1 are same */
      /* time compplexity O()
         space complexity O()
          leetcode link = https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150*/ 


          class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxPointsOnLine = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<double, int> slopeCount;
            int duplicates = 1; // for the point itself
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++; // same point
                } else {
                    double slope = (dx == 0) ? INT_MAX : (double)dy / dx;
                    slopeCount[slope]++;
                }
            }

            int localMax = 0;
            for (auto &entry : slopeCount)
                localMax = max(localMax, entry.second);

            maxPointsOnLine = max(maxPointsOnLine, localMax + duplicates);
        }

        return maxPointsOnLine;
    }
};
