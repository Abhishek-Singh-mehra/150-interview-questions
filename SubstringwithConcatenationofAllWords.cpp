/*You are given a string s and an array of strings words. All the strings of words are of the same length.
A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings.
 "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.*/
/* ***************************approach 1 *****************************/
/* brute force approach
                      1. generate the permutation
                       2  then check if it apprar in s push  to ans.*/
/* time complexity 0(n!)
space complexity 0(1).*/
class solution
{
public:
    vector<int> findstring(string s, vector<string> &words)
    {
        vector<int> result;
        if (words.empty())
            return result;
        int wordlen = words[0].size();
        int totallen = wordlen * words.size();
        sort(words.begin(), words.end()); // for gettng permutation in lexographical order .
        do
        {
            string concat;
            for (strings &word : words)
                concat += word;
            size_t pos = s.find(concat);
            while (pos != string::npos)
            {
                result.push_back(pos);
                pos = s.find(concat, pos + 1);
            }
        } while (next_permutation(words.begin(), words.end()));
        return result;
    }
}