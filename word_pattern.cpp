/*
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
 */ 
/***********************approach 1 ****************************** */
 /* its the follow up question of the isomorphic string . we do same  as the previous quetion two unordered_map and sheck if they are present or 
 indicates to the same one strifng or ch if not then false .*/ 
 /* time complexity 0(n).
   spcae complexity 0(n).
    leetcode problem link =https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150*/ 
    class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // to get the string of words seprately with thespace and store then in the vector.
        vector<string>words;
        stringstream ss(s);
        string w ;
         while( ss>>w)words.push_back(w);

         if(words.size()!= pattern.size()) return false ;

         unordered_map<char , string >p2w;
          unordered_map<string,char>w2p;
           for(size_t i=0 ; i<pattern.size() ; i++)
            {
                     char ch = pattern[i];
                      const string &word = words[i];
                      auto itp = p2w.find(ch);
                       // if  word of pattern is indicates to the word.
                      if(itp!=p2w.end())
                      {
                         if(itp->second !=word) return false ;
                      } 
                      else
                      {
                         //if string word indicates to  the  pattern ch .
                        auto itw = w2p.find(word);
                        if(itw !=w2p.end())
                        {
                             if(itw->second !=ch) return false;
                        }
                        p2w[ch] = word ;
                        w2p[word] = ch ;
                      }
            }  

            //if we get to the last menas all set .
            return true ;
    }
};