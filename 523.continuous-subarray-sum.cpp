/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int l = nums.size();
        int mod;
        long long sum = 0;

        if (l < 2)
            return false;

        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < l; i++) {
            sum += nums[i];

            mod = sum % k;

            if (mp.find(mod) != mp.end()) {
                if (i - mp[mod] > 1) {
                    return true;
                }
            } else {
                mp[mod] = i;
            }
        }

        return false;
    }
};
// @lc code=end

