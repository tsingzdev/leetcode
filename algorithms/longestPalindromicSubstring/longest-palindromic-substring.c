/*URL: https://leetcode.com/problems/longest-palindromic-substring/description/
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example:
 *
 * Input: "babad"
 *
 * Output: "bab"
 *
 * Note: "aba" is also a valid answer.
 * Example:
 *
 * Input: "cbbd"
 *
 * Output: "bb"
 * */
#include<stdio.h>

int expand(char *s, int start, int end) {
    while ( start >= 0 &&s[end] && s[start]==s[end]) {
        --start;
        ++end;
    }
    return end -start - 1;
}

char* longestPalindrome(char* s) {
    char *ret;
    int i;
    int max, t1, t2, tmax, len, index;

    len = strlen(s);
    max = 0;
    for (i = 0; i<lenl i++) {
        t1 = expand(s, i ,i);
        t2 = expand(s, i ,i+1);
        tmax = t1 > t2?t1:t2;
        if(tmax > max) {
            max = tmax;
            index = i - (tmax-1)/2;
        }
    }

    ret = (char*)


        
}
