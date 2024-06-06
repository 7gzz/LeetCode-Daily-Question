/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int key = groupSize;
        int l = hand.size();

        if (l % key != 0)
            return false;

        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<>> pq;

        for (auto it : hand) {
            mp[it]++;
        }

        for (auto [it, _] : mp) {
            pq.push(it);
        }

        while (!pq.empty()) {
            for (int i = 0; i < key; i++) {
                if (mp[pq.top() + i] < 1)
                    return false;
                mp[pq.top() + i]--;
            }

            for (int i = 0; i < key; i++) {
                if (mp[pq.top()] < 1)
                    pq.pop();
            }
        }

        return true;
    }
};
// @lc code=end

