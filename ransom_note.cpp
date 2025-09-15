/*Given two strings ransomNote and magazine, 
return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.*/
 /* ***********************approach 1 ************************/
  /* the approach is tha we store  the word with thier countin hte unordered_map and the n
   traversal in the ransomnote string if we  do not find or the count of the ch
    is  0 then  return false other wise subtract the frequency of the ch.*/
     /* time complexity 0(n).
      space complexity 0(n).
       leetcode link  =https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150*/ 
       class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char , int>mp;
        // store  the magazine  ch in the map
         for( char & ch : magazine)
         {
             mp[ch]++;
         } 
           int i =0;
          while (i<ransomNote.length())
          {
             if(mp.find(ransomNote[i]) ==mp.end() || mp[ransomNote[i]]==0 )
             {
                return false ;
             } 
             mp[ransomNote[i]]--;
             i++;
          } 
            return true ;
         }
}; 