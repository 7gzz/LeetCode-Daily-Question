/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
class Solution {
public:
    struct TrieNode {

        TrieNode* childNode[26];

        bool wordEnd;

        TrieNode() {
            wordEnd = false;

            for (int i = 0; i < 26; i++) {
                childNode[i] = nullptr;
            }
        }
    };

    void insert(TrieNode* root, string& key) {
        TrieNode* currentNode = root;

        for (auto it : key) {
            if (currentNode->childNode[it - 'a'] == nullptr) {
                TrieNode* newNode = new TrieNode();
                currentNode->childNode[it - 'a'] = newNode;
            }

            currentNode = currentNode->childNode[it - 'a'];
        }

        currentNode->wordEnd = true;
    }

    string search(TrieNode* root, string& key) {
        string word = "";

        TrieNode* currentNode = root;

        for (auto it : key) {

            if (currentNode->wordEnd)
                return word;

            if (currentNode->childNode[it - 'a'] == nullptr) {
                if (currentNode->wordEnd)
                    return word;
                else
                    return "";
            }

            word += it;
            currentNode = currentNode->childNode[it - 'a'];
        }

        if (currentNode->wordEnd)
            return word;
        else
            return "";
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        string answer = "";
        vector<string> v;
        TrieNode* root = new TrieNode();

        for (auto it : dictionary) {
            insert(root, it);
        }

        sentence.push_back(' ');

        for (auto it : sentence) {
            if (it != ' ') {
                answer += it;
            } else {
                v.push_back(answer);
                answer = "";
            }
        }

        for (auto it : v) {
            string str = search(root, it);

            if (str == "") {
                answer += it;
                answer += ' ';
            } else {
                answer += str;
                answer += ' ';
            }
        }

        answer.pop_back();

        return answer;
    }
};
// @lc code=end

