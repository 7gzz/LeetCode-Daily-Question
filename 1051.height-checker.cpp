/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int l = heights.size();
        int c=0;

        vector<int>orderd_heights = heights;
        sort(orderd_heights.begin(),orderd_heights.end());

        for(int i=0;i<l;i++)
        {
            if(heights[i]!=orderd_heights[i]) c++;
        }

        return c;
    }
};
// @lc code=end

