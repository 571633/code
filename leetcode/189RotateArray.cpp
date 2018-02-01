Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v(nums.size(), 0);
        for(int i=0; i<nums.size(); i++) {
            v[(i+k)%nums.size()] = nums[i];
        }
        nums = v;
    }
};

class Solution {
public:
    void reverse(vector<int>&v, int i, int j) {
        while(i<j)
            swap(v[i++], v[j--]);
    }
    void rotate(vector<int>& v, int k) {
        if(!v.size())
            return ;
        k = k%v.size();
        if(k%v.size()==0)
            return ;
        reverse(v, 0, v.size()-k-1);
        reverse(v, v.size()-k, v.size()-1);
        reverse(v, 0, v.size()-1);
    }
};

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            if(nums.size()==0)
                return ;
            k = k%nums.size();
            if(!k)
                return;
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin()+k);
            reverse(nums.begin()+k, nums.end());
        }
};
