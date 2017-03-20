Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:

    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream in(str);
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        int k = 0;  // string pattern index
        for(string word; in >> word; k++) {
            if(m1.count(pattern[k]) == 0 && m2.count(word)==0) {
                m1[pattern[k]] = word, m2[word] = pattern[k];
                continue;
            }
            if(m1[pattern[k]] != word || m2[word]!=pattern[k]) {
                return false;
            }
        }
        return k==pattern.size();
    }
};
