/*A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, 
return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.*/ 
 
 
/****************************************************** approach 1 ******************************************************** */
/*the  approach is that to use the bfs to get the smallest path to get at the endword so we will use the  unorderedmap or the set which store the 
  dictonary word  with the value to false the we will traverse the bfs from starting word and   first pop the  string from the front of 
  queue the nmake it true to the map as we have got this and  increment the steps  now wew ill change the every char of the queue  front word and check for 
  the next word whcih is present in the map and have the value false.then insert it to the queue. */
   
  /* time complexity O(N. L^2) N is rhe number of words in wordset
                               L is the length of the each word.
    space complexity O(N.L)
    leetcode link = https://leetcode.com/problems/word-ladder/description/?envType=study-plan-v2&envId=top-interview-150*/

    class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordset(wordList.begin() , wordList.end()); 
         
         if(wordset.find(endWord)==wordset.end()) return 0;
        queue<string>que;
         que.push(beginWord);
         int steps =1 ;
          while(!que.empty())
          {
             int size = que.size();
              for(int i=0 ; i<size ; i++)
              {
                  string word = que.front();
                  que.pop();
                  if(word ==endWord) return steps;
  
                  for(int j =0 ; j<word.size() ; j++)
                  {
                      char original = word[j];
                       for(char c ='a' ;c<='z' ; c++)
                       {
                         word[j]=c;
                         if(wordset.find(word)!=wordset.end())
                         {
                             que.push(word);
                             wordset.erase(word);
                         }
                       }
                       word[j] =original;
                  }
              }
              steps++;
          }
          return 0;
    }
};