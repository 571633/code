Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ret = 0;
        for(int i=0; i<s.size(); i++) {
            if(i>0 && m[s[i-1]]<m[s[i]]) {
                ret = ret+m[s[i]]-2*m[s[i-1]];
            } else {
                ret += m[s[i]];
            }
        }
        return ret;
    }
};
