/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int l = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> v = nums;

        int answer = 0;

        for (int i = 1; i < l; i++) {
            if (nums[i] == nums[i - 1])
                nums[i]++;
            else if (nums[i] < nums[i - 1])
                nums[i] = nums[i - 1] + 1;
        }

        for (int i = 0; i < l; i++) {
            answer += abs(nums[i] - v[i]);
        }

        return answer;
    }
};
// @lc code=end

