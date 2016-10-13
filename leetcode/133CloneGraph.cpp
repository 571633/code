 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return nullptr;
        
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        m[node] = new UndirectedGraphNode(node->label);
        q.push(node);
        while(!q.empty()) {
            UndirectedGraphNode* n = q.front();
            q.pop();
            for(int i=0; i<n->neighbors.size(); i++) {
                if(!m.count(n->neighbors[i])) {
                    m[n->neighbors[i]] = new UndirectedGraphNode(n->neighbors[i]->label);
                    q.push(n->neighbors[i]);
                }
                m[n]->neighbors.push_back(m[n->neighbors[i]]);
            }
        }
        return m[node];
    }
};
