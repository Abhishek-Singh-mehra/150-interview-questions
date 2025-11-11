/*Given a string s and a dictionary of strings wordDict, 
return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.*/ 

/**************************** approach 1 ********************************** */
 /* the intution is that we will  form the tree pick the word and  check in the dictionary if we find  it their we will fins the next word 
  at last if the indx is at last  and find the word the n we wil return the true . other wise  false .*/
  /* time complexity O(2^n)
     space complexity O(n) */

     class Solution {
public:
    unordered_set<string> st;
    int n;
    
    bool solve(string &s, int idx) {
        
        if(idx == n) {
            return true;
        }

        if(st.find(s.substr( idx , n - idx )) != st.end()) {
            return true;
        }
        
       
        for(int l = 1; l<=n; l++) {
            
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(s, idx+l))
                return  true;
            
        }
        
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
       
        
        for(string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(s, 0);
    }
}; 



/*********************** approach 2 ************************ */ 
/* we will do the memorization of the  each word if we get in future 
 we will directly return true */
  /* time complexity O()
     space complexity O(n)
     leetcode link = https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150*/ 

     class Solution {
public:
    unordered_set<string> st;
    int t[301];
    int n;
    
    bool solve(string &s, int idx) {
        
        if(idx == n) {
            return true;
        }

        if(st.find(s.substr( idx , n - idx )) != st.end()) {
            return true;
        }
        
        if(t[idx] != -1)
            return t[idx];
        
        for(int l = 1; l<=n; l++) {
            
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(s, idx+l))
                return t[idx] = true;
            
        }
        
        return t[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
        memset(t, -1, sizeof(t));
        
        for(string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(s, 0);
    }
}; 

