/* 
reorder the data from the log file:
all lines with words are at the top in the log file, in lexicographical order;
Words are ordered lexicographically ignoring the identifier except in the case of ties.
In the case of ties, the id is used to order lexicographically.
Alphanumerics should be sorted in ASCII order (number come before letters)
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

typedef struct logData
{
    string id;
    string data;
    bool operator< (const logData& rhs)
    {
        char c1 = data[0], c2 = rhs.data[0];
        if(isdigit(c1) && isdigit(c2)) {
            if(data != rhs.data)
                return data < rhs.data;
            return id > rhs.id;
        } else if(isdigit(c1) && !isdigit(c2)) {
            return 1;
        } else if(!isdigit(c1) && isdigit(c2)) {
            return 0;
        } else if(!isdigit(c1) && !isdigit(c2)) {
            if(data != rhs.data)
                return data > rhs.data;
            return id > rhs.id;
        }
        return 0;
    }
}logData;

vector<string> reorder(vector<string> logLines)
{
    vector<logData> v;
    for(size_t i=0; i<logLines.size(); i++)
    {
        logData l;
        istringstream iss(logLines[i]);
        iss >> l.id;
        l.data = logLines[i].substr(l.id.size()+1);
        v.push_back(l);
    }

    sort(v.begin(), v.end());
    vector<string> ret;
    for(size_t i=0; i<v.size(); i++)
    {
        ret.push_back(v[i].id + " " + v[i].data);
    }
    return ret;
}

int main()
{
    string s[] = {"a1 9 2 3 1", 
        "g1 Act car",
        "zo4 4 7",
        "ab1 off Key dog",
        "a8 act zoo"
    };
    vector<string> ret = reorder(vector<string>(s, s+5));
    for(size_t i=0; i<ret.size(); i++)
        cout<<ret[i]<<"\n";
}
