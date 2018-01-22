//URL:https://leetcode.com/problems/group-anagrams/description/
/*Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 *
 * Note: All inputs will be in lower-case.
 *
 **/


//#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> & strs){
        unordered_map<string, vector<string>> groups;
        for (const auto& str : strs) {
            string tmp{str};
            sort(tmp.begin(),tmp.end());
            groups[tmp].emplace_back(str);
        }

        vector<vector<string>> anagrams;
        for (const auto& kvp : groups) {
            vector<string> group;
            for (const auto& str : kvp.second) {
                group.emplace_back(str);
            } 
            sort(group.begin(), group.end());
            anagrams.emplace_back(move(group));
        }

        return anagrams;
    }
};

/*
int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solutions s;
    auto ans = s.groupAnagrams(strs);

    for(int i = 0; i < ans.size(); i++) {
        for (int j = 0; j< ans[i].size(), j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
