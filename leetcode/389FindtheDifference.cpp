Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.


class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> m(26, 0);
        
        for(int i=0; i<s.length(); i++)
           m[s[i] - 'a']++;
        for(int i=0; i<t.length(); i++) {
            m[t[i] - 'a']--;
            if(m[t[i] - 'a'] < 0)
                return t[i];
        }
        return 0;
    }
};


class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<s.size(); i++) {
            if(s[i]!=t[i])
                return t[i];
        }
        return t.back();
    }
};
