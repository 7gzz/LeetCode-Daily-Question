/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int l = s.size();
        int c = 0;
        map<char, int> freq;

        for (int i = 0; i < l; i++)
        {
            freq[s[i]]++;
        }

        for (auto it : freq)
        {
            if (it.second > 1)
                c += (it.second / 2) * 2;
        }

        if (l > c && c % 2 == 0)
            c++;
        return c;
    }
};
// @lc code=end
