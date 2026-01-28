#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
   public:
    TrieNode *children[26];

    bool isLeaf;

    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode *root, const string &key) {
    TrieNode *curr = root;

    for (char c : key) {
        if (curr->children[c - 'a'] == nullptr) {
            TrieNode *newNode = new TrieNode();

            curr->children[c - 'a'] = newNode;
        }

        curr = curr->children[c - 'a'];
    }

    curr->isLeaf = true;
}

bool search(TrieNode *root, const string &key) {
    if (root == nullptr) {
        return false;
    }

    TrieNode *curr = root;

    for (char c : key) {
        if (curr->children[c - 'a'] == nullptr) return false;

        curr = curr->children[c - 'a'];
    }

    return curr->isLeaf;
}

vector<int> findSubstring(string s, vector<string> &words) {
    TrieNode *root = new TrieNode();
    for (const string &word : words) {
        insert(root, word);
    }

    auto wordLength = words[0].size();
    auto totalWords = words.size();
    auto stringLength = s.size();
    auto substringLength = wordLength * totalWords;

    unordered_map<string, int> wordCount;

    vector<int> result;
    for (int i = 0; i <= stringLength - substringLength; i++) {
        vector<string> seenWords;
        for (int j = 0; j < totalWords; j++) {
            string currentWord = s.substr(i + j * wordLength, wordLength);
            if (search(root, currentWord)) {
                seenWords.push_back(currentWord);
            } else {
                break;
            }
        }

        if (seenWords.size() == totalWords) {
            vector<string> tempWords = words;
            sort(tempWords.begin(), tempWords.end());
            sort(seenWords.begin(), seenWords.end());
            if (tempWords == seenWords) {
                result.push_back(i);
            }
        }
    }

    return result;
}

int main() {
    vector<string> arr = {"foo", "bar"};

    findSubstring("barfoothefoobarman", arr);

    return 0;
}
