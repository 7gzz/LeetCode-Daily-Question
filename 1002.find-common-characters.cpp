/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<vector<int>> hashmap;
        vector<int> freq(26, 0);
        vector<string> answer;

        for (auto it : words) {
            fill(freq.begin(), freq.end(), 0);

            for (auto c : it) {
                freq[c - 'a']++;
            }

            hashmap.push_back(freq);
        }
        int n = hashmap.size();
        int minimum = 0;

        string s;

        for (int i = 0; i < 26; i++) {
            minimum = 101;

            for (int j = 0; j < n; j++) {
                minimum = min(minimum, hashmap[j][i]);
            }

            for (int k = 0; k < minimum; k++) {
                s = "";
                s += char(i + 'a');
                answer.push_back(s);
            }
        }

        return answer;
    }
};
// @lc code=end

