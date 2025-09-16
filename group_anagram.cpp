/*Given an array of strings strs, 
group the anagrams together. You can return the answer in any order.
 */
  /************************the approach 1 *************** */
   /* the intutuion is simple  the string always get into the gategory of its string in sorted order
   if we  store the string in its sorted order then we can store all the 
   string of anagram in the smae gruop. so we use unordered_map and store the string
   in its sortedoreder 
   like this  abc --->bca , cab. */
    /* time  complexity o(n)
    space complexity o(1) given max 100.
    leetcode link = https://leetcode.com/problems/group-anagrams/?envType=study-plan-v2&envId=top-interview-150*/
    class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
         vector<vector<string>>res ; 
         unordered_map<string , vector<string>>mp;
          for(  int  i =0; i<n ; i++)
          {
              string temp = strs[i];
               sort(temp.begin()  ,temp.end());
               mp[temp].push_back(strs[i]);
          }
           for(auto i:mp)
           {
              res.push_back(i.second);
           }
          return res ;
    }
};