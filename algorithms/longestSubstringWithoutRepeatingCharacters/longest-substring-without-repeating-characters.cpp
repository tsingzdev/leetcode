/*URL:https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 * */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

//Solution 1:
int lengthOfLongestSubstring(string s) {
    const int MAX_CHARS = 256;
    int m[MAX_CHARS];
    memset(m ,-1, sizeof(m));

    int maxLen = 0;
    int lastRepeatPos = -1;
    for( int i =0; i<s.size(); i++) {
        if(m[s[i]]!= -1&& lastRepeatPos < m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if(i - lastRepeatPos > maxLen) {
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen;
} 

//Solution 2: using a map 
int lengthOfLongestSubstring1(string s) {
    map<char, int> m;
    int maxLen = 0;
    int lastRepeatPos = -1;

    for(int i=0; i<s.size(); i++) {
        if(m.find(s[i])!= m.end() && lastRepeatPos <= m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if(i - lastRepeatPos > maxLen) {
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen;
}

int main ( int argc, char**argv) {
    string s = "abcabcbb";
    cout << s << ":" << lengthOfLongestSubstring(s) << endl;

    s = "pwwkew";
    cout << s << ":" << lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << s << ":" << lengthOfLongestSubstring(s) << endl;

    if (argc >1) {
        s = argv[1];
        cout << s << ":" << lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}

