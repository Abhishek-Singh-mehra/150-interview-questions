/*Given two strings s and t, 
return true if t is an anagram of s, and false otherwise.
 */
 /* ***********************approach1 **********************/
 /* the intutuion is that we make an vectro of 26 and fill  the characters 
 counts and then travel inthe t string and stat to decrement last
  if  all the idx are 0 return true otherwise false .*/
  /* time compleixt 0(n)
   space complexity 0(1) constant space.
   */
  class Solution {
public:
    bool isAnagram(string s, string t) {
        if (size(s) != size(t)) {
            return false;
        }

        vector<int> counts(26, 0);

        for (char c : s) {
            counts[c - 'a']++;
        }

        for (char c : t) {
            counts[c - 'a']--;
        }

        for (int i : counts) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};

/**********************************approach2 ********************** */
/* the intuion is that we store it in the unordered_map with freq then travel to 
the  other strign and subtract he freq if we encounter the 0 or not found then false*/
/* time compleixt 0(n).
  space  complexity 0(1).
   leetcode link = https://leetcode.com/problems/valid-anagram/?envType=study-plan-v2&envId=top-interview-150*/ 
   class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false ;
         unordered_map<char , int>mp;
          for( auto ch : t)
          {
             mp[ch]++;
          } 
           // now to compare ;
           for( char & ch :s)
           {
              if(mp.find(ch) ==mp.end() || mp[ch]==0) return false ;
              else
              {
                 mp[ch]--;
              }
           } 
            return true ;
    }
};