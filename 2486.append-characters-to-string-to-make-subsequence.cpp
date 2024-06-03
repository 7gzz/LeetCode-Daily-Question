/*
 * @lc app=leetcode id=2486 lang=cpp
 *
 * [2486] Append Characters to String to Make Subsequence
 */

// @lc code=start
class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int count = 0;
        int flag = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (count == t.size())
                break;

            if (t[count] == s[i])
            {
                count++;
                flag = 1;
            }
        }

        return t.size() - count;
    }
};
// @lc code=end
