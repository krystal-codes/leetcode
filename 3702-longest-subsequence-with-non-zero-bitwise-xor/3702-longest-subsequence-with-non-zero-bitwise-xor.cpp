class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool non_zero = false;
        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
            if(nums[i] != 0) non_zero = true;
        }
        if(xr == 0 and non_zero) return n - 1;
        else if(!non_zero) return 0;
        else return n;
    }
};