/*URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *Given a string, find the length of the longest substring without repeating characters.

 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. 
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 * */

int lengthOfLongestSubstring(char* s) {   
    const int MAX_CHARS = 256;
    int index[MAX_CHARS];        
    int last_index;
    int i ,ret;

    memset(index, 0, sizeof(int)*MAX_CHARS);
    last_index = -1;

    ret = 0;
    for (i = 0; i<strlen(s); i++) {
        last_index = index[s[i]] > last_index ? index[s[i]] : last_index;
        index[s[i]] = i+1;
        ret = (i - last_index +1 > ret) ? i-last_index +1:ret;
    }
    return ret;    
}



