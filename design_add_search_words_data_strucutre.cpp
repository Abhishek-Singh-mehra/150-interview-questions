/*Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
word may contain dots '.' where dots can be matched with any letter.*/ 
 
/****************************************** approach 1 ************************************************* */ 
 /* the intution is simple wew will use the tri data structure same as t oinsert the word but when it time 
 to search the word wew ill ad the  dot function whic hwe do ,put the alphabet from the a to z in the dot place and check for the further 
 if the word is present in it if it return the true that menas the  whole word is present other wise false .*/ 

 /* time compleixty  insertion O(n) ,search O(n)
    space compleixty O(A*L) total length of words accross the words(L) , and A means the total alphabet used .
    leetcodel ink = https://leetcode.com/problems/design-add-and-search-words-data-structure/?envType=study-plan-v2&envId=top-interview-150*/ 

    class WordDictionary {
public: 
    struct trinode{ // class.
         bool endofword;
         trinode * children[26];
    } ;

     trinode * getnode (){
          trinode * newnode = new trinode();
          newnode->endofword = false;
          for(int i=0; i<26 ; i++)
          {
             newnode ->children[i]= NULL;
          } 
          return newnode;
     } 
     trinode *root ;
    WordDictionary() {
         root = getnode();
    }
    
    void addWord(string word) {
        // same as insert to the tri.
         trinode * crawl = root ;
          for(int i=0; i< word.length() ; i++)
          {
            char  ch = word[i];
             int indx = ch-'a';
             if(crawl->children[indx]==NULL){
                  //menas i have ot make a treinode.
                  crawl->children[indx] =getnode();
             } 
             crawl  =crawl->children[indx];
          } 
          crawl ->endofword =true;
    }
    
    bool search(string word) {
         trinode * crawl = root ;
          for(int i=0; i<word.length() ; i++)
          { 
            char ch = word[i];
            int indx = ch-'a'; 
            if(ch=='.')
            {
                 for(int j=0 ;j< 26 ; j++)
                 {
                      if(crawl->children[j]!=NULL)
                      {
                         // recursive call.
                          string word2 = word;
                           word2[i]='a'+j;
                           if(search(word2)) return true;
                      }
                 }
                 return false;
            }
             if(crawl ->children[indx]==NULL) return false;
            crawl = crawl->children[indx];
          }
         return crawl->endofword;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */