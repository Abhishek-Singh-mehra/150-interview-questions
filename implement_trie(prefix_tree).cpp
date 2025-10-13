/*A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.*/ 
 
 
/********************************************** approach 1 ******************************************************** */
/* the intution is simle that we build a trie tree and fill the things into it if not present and if present then return true.*/ 
/* leetcode link = https://leetcode.com/problems/implement-trie-prefix-tree/?envType=study-plan-v2&envId=top-interview-150 */ 

class Trie {
public: 
 struct triNode{
     bool isendofword;
     triNode* children[26];
 };
 triNode * getNode(){
     triNode * newNode = new triNode();
     newNode ->isendofword =  false ; 
      for(int i=0 ; i< 26 ; i++)
      {
         newNode ->children[i] = NULL;
      }
      return newNode ;
 }
  triNode* root ;
    Trie() {
         root  = getNode();
    }
    
    void insert(string word) {
         triNode * crawler = root;
         for( int i =0 ; i< word. length() ; i++)
         {
              char ch = word[i];
               int idx = ch-'a';

               if( crawler ->children[idx] ==NULL)
               {
                 crawler ->children[idx] = getNode();
               }
               crawler  = crawler->children[idx];
         }
         crawler ->isendofword =true;
    }
    
    bool search(string word) {
         triNode * crawler = root;
         for( int i =0 ; i< word. length() ; i++)
         {
              char ch = word[i];
               int idx = ch-'a';

               if( crawler ->children[idx] ==NULL)
               {
                 return false ;
               }
               crawler  = crawler->children[idx];
         }
         if(crawler!=NULL && crawler->isendofword ==true ) return true ;
         else return false ;
    }
    
    bool startsWith(string prefix) {
        triNode * crawler = root; 
        int i =0;
         for(  i =0 ; i< prefix.length() ; i++)
         {
              char ch = prefix[i];
               int idx = ch-'a';

               if( crawler ->children[idx] ==NULL)
               {
                 return false ;
               }
               crawler  = crawler->children[idx];
         }
         if(i== prefix.length() ) return true ;
         else return false ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */