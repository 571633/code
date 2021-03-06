Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3]




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preorderTraversal(TreeNode* root, vector<int>& v) {
        if(!root)
            return ;
        v.push_back(root->val);
        preorderTraversal(root->left, v);
        preorderTraversal(root->right, v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorderTraversal(root, v);
        return v;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            while(s.top()) {
                v.push_back(s.top()->val);
                s.push(s.top()->left);
            }
            s.pop();
            if(!s.empty()) {
                TreeNode *t = s.top();
                s.pop();
                s.push(t->right);
            }
        }

        return v;
    }
};
