#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        if (words.find(endWord) == words.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        words.erase(beginWord);

        while (!q.empty()) {
            string current = q.front().first;
            int length = q.front().second;
            q.pop();

            if (current == endWord)
                return length;

            for (int i = 0; i < current.size(); i++) {
                char original = current[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original)
                        continue;

                    current[i] = c;

                    if (words.find(current) != words.end()) {
                        q.push({current, length + 1});

                        words.erase(current);
                    }
                }

                current[i] = original;
            }
        }

        return 0;
    }
};