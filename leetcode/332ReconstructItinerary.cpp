Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

    If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
    All airports are represented by three capital letters (IATA code).
    You may assume all tickets form at least one valid itinerary.

Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order. 

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, map<string, int>> m;
        for(int i=0; i<tickets.size(); i++) {
            m[tickets[i].first][tickets[i].second]++;
        }
        vector<string> v;
        v.push_back(string("JFK"));
        dfs(m, v, tickets.size()+1, "JFK");
        return v;
    }
    
    bool dfs(map<string, map<string, int>> &m, vector<string>&v, int n, string res) {
        if(v.size() == n)
            return true;
        for(auto it=m[res].begin(); it!=m[res].end(); it++) {
            if(it->second) {
                v.push_back(it->first);
                it->second--;
                if(dfs(m, v, n, v.back()))
                    return true;
                v.pop_back();
                it->second++;
            }
        }
        return false;
    }
};
