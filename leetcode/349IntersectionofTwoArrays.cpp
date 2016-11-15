 Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

    Each element in the result must be unique.
    The result can be in any order.


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        set<int> t;
        for(int i=0; i<nums1.size(); i++)
            s.insert(nums1[i]);
        for(int i=0; i<nums2.size(); i++) {
            if(s.count(nums2[i]))
                t.insert(nums2[i]);
        }
        return vector<int>(t.begin(), t.end());
    }
};