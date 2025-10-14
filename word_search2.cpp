/*Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
 The same letter cell may not be used more than once in a word.
 */


 /****************************************** approach 1 ******************************************* */ 
  /*  we willfind all the words in the board individual with the help of dfs  and also mark the visited board initial with false and later true
   when we will  trverse that word in the board .*/
    /* time complexity  O(N*M*W*4^L) w is word length.
       space compleixty O(N*M +L)*/ 

       class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int index, int x, int y,
             vector<vector<bool>>& visited) {
        if (index == word.size())
            return true;
        int n = board.size(), m = board[0].size();

        if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] ||
            board[x][y] != word[index])
            return false;

        visited[x][y] = true;

        bool found = dfs(board, word, index + 1, x + 1, y, visited) ||
                     dfs(board, word, index + 1, x - 1, y, visited) ||
                     dfs(board, word, index + 1, x, y + 1, visited) ||
                     dfs(board, word, index + 1, x, y - 1, visited);

        visited[x][y] = false; // backtrack
        return found;
    }
    bool checkifexists( string word, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        // create a  copy of the board.
        vector<vector<bool>>visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, 0, i, j, visited))
                    return true;
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        vector<string> results;
        string ans;

        for (int i = 0; i < words.size(); i++) {
            // check   for the string is present or not .
            if (checkifexists(words[i], board))
                results.push_back(words[i]);
        }
        return results;
    }
};



/*************************************************** approach 2 *********************************************** */ 
 /*Instead of checking each word individually, build a Trie from the word list and run DFS once from each cell on the board. This way:
You prune invalid paths early using Trie prefixes.
You avoid redundant DFS calls for words with shared prefixes. */ 
 /* time compleixty  𝑂(𝑊⋅𝐿+𝑁⋅𝑀⋅4𝐿)
   cpace complexity 𝑂(𝑊⋅𝐿+𝑁⋅𝑀)
    leetcode link =https://leetcode.com/problems/word-search-ii/submissions/1801224026/?envType=study-plan-v2&envId=top-interview-150*/ 

    class Solution {
public:
    struct TrieNode {
        bool isWord = false;
        string word = "";
        TrieNode* children[26] = {nullptr};
    };

    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isWord = true;
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];
        if (node->isWord) {
            result.push_back(node->word);
            node->isWord = false; // avoid duplicates
        }

        board[i][j] = '#'; // mark visited
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size()) {
                dfs(board, x, y, node, result);
            }
        }
        board[i][j] = c; // backtrack
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) insert(root, word);

        vector<string> result;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }
};


