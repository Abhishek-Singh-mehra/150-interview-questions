/*Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital,
LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources,
it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
The answer is guaranteed to fit in a 32-bit signed integer.*/

/* ******************************* approach 1 ***********************************************/
/* the intution is that we will iterate in  the  capital vec  till k ==0 we will pick that capitalthat is equal to the  capital we have or
   the smaller capital that we get wiith the maximum profit from the profit vec then add it to the our capital and  mark that capital as visited.*/
/* time complexity O(k.n)
   space complexity O(1)*/

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int totalprofit = w;
        int n = capital.size();
        int a = 0;

        while (k != 0)
        {
            int i = 0;
            int idx = -1;

            for (; i < n; i++)
            {
                if (capital[i] <= w && profits[i] > a)
                {
                    a = profits[i];
                    idx = i; // mark the best project index
                }
            }

            if (idx == -1)
                break; // no project can be picked

            // now add to profit
            totalprofit += a;
            w += a;
            a = 0;
            k--;

            // mark project as used
            profits[idx] = -1; // or any sentinel value to skip next time
        }

        return totalprofit;
    }
};

/****************************************** approach 2 ********************************** */
/*  a s we have seen in the above aproach what if we can sort the capital vec we can know that  grater than the w we are not able to pick
 and than we can us e the priority queue to store all the small nad the equal  capital to extract / add it to the  original capital.*/
/* time complexity O(nlogn)
   space complexity O(n)
    leetcode link= https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150*/

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++)
        {
            vec[i] = {capital[i], profits[i]};
        }

        // sort
        sort(vec.begin(), vec.end());

        int i = 0;
        priority_queue<int> pq;
        while (k--)
        {
            while (i < n && vec[i].first <= w)
            {
                pq.push(vec[i].second);
                i++;
            }
            if (pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};