/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3] = {0,0,0};
        
        for(auto it:nums)
        {
            a[it]++;
        }

        nums.clear();

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<a[i];j++)
            {
                nums.push_back(i);
            }
        }
    }
};
// @lc code=end

