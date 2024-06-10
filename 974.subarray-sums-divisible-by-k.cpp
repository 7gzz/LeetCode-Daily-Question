/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int l = nums.size();
        int mod;
        long long sum = 0;
        int counter = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < l; i++) {

            sum += nums[i];

            mod = (sum % k + k) % k;

            mp[mod]++;

            if (mp[mod] > 1) {
                counter += mp[mod] - 1;
            }
        }

        return counter;
    }
};
// @lc code=end

