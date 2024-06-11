/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> answers;
        map<int, int> hashmap;

        for (auto it : arr1) {
            hashmap[it]++;
        }

        for (auto it : arr2) {
            if (hashmap[it] > 0) {
                for (int i = 0; i < hashmap[it]; i++) {
                    answers.push_back(it);
                }

                hashmap[it] = 0;
            }
        }

        for (auto& it : hashmap) {
            if (it.second > 0) {
                for (int i = 0; i < it.second; i++) {
                    answers.push_back(it.first);
                }
            }
        }

        return answers;
    }
};
// @lc code=end

