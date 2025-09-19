/*You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti.
 You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.*/

/******************************************approach 1 ************************** */
/*  precautions  ---> this is question require the concpt of the summary range and merge interval question
     take care of the  edges case starting and the last  edge case  and  question is done . */
/* we first trave  with te i and chcek with the new insetred intervals if
 they  interval[i][1]>=newinterval[0] they it need to be inserted
 so after  merging with the prev we want to look forward that  their next
  interval also overlapping or not if yes teh nmerge then with the i interval
  lastly if the newinterval is not merged then it should eb adde dat last .*/
/*time complexity 0(n).
  space compleixty 0(n).
  leetcode link =  https://leetcode.com/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150*/

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<vector<int>> res;
        bool inserted = false;
        int n = intervals.size();

        for (int i = 0; i < n; i++)
        {

            if (intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[0] && !inserted)
            {
                // merge with newInterval
                intervals[i][1] = max(intervals[i][1], newInterval[1]);
                intervals[i][0] = min(intervals[i][0], newInterval[0]);

                // check overlaps with following intervals
                int j = i + 1;
                while (j < n)
                {
                    if (intervals[i][1] >= intervals[j][0])
                    {
                        intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }

                res.push_back(intervals[i]);
                inserted = true;
                i = j - 1; // skip merged ones
            }
            else
            {
                if (!inserted && newInterval[1] < intervals[i][0])
                {
                    res.push_back(newInterval);
                    inserted = true;
                }
                res.push_back(intervals[i]);
            }
        }

        // if newInterval comes after all
        if (!inserted)
            res.push_back(newInterval);

        return res;
    }
};
