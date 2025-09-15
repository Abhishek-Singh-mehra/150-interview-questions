/*Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.*/ 

 /* ************************** approach 1 ********************************/
 /* the intution is that we store the replace eleemnt into the hashmap to each other 
  we use two hash map for this one for s to t and one for t to s 
   if they are replace equa lthe nit is good no matter how many time .
    if not then false andin the startingit thay are not present the nwe have to put it in the map .*/
     /* time complexity 0(n)
      space complexity 0(1);
      leetcode  problme lonk = https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150*/ 
      class Solution {
    public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> map_s_to_t;
        unordered_map<char, char> map_t_to_s;

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i], c2 = t[i];

            if (map_s_to_t.count(c1) && map_s_to_t[c1] != c2)
                return false;
            if (map_t_to_s.count(c2) && map_t_to_s[c2] != c1)
                return false;

            map_s_to_t[c1] = c2;
            map_t_to_s[c2] = c1;
        }

        return true;
    }
};
